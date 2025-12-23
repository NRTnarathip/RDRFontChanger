using System.CommandLine;
using System.Diagnostics;
using TranslatorTool;


internal class Program
{
    private static async Task Main(string[] args)
    {
        try
        {
            GlobalConfig.Init(args);
            await Run();
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex);
        }

        // ready to run
        Console.WriteLine("Press any key to close.");
        Console.ReadLine();
    }

    private static async Task Run()
    {
        var srcFilepath = GlobalConfig.InputSourcePath;
        var srcFileInfo = new FileInfo(srcFilepath);
        if (srcFileInfo.Exists == false)
            throw new FileNotFoundException(srcFilepath);

        string fileExt = srcFileInfo.Extension;
        Stopwatch saveFileTimer = Stopwatch.StartNew();

        string k_suffixSaveFilepath = "@ai_translate" + fileExt;
        var saveFilePath = srcFilepath.Replace(fileExt, k_suffixSaveFilepath);
        Console.WriteLine("save output path: " + saveFilePath);
        // create it!
        if (!File.Exists(saveFilePath))
        {
            File.Copy(srcFilepath, saveFilePath);
            Console.WriteLine("create new output file!");
        }

        // setup AI Translator Tool
        var ai = new ThaiAITranslator();

        // ready to load
        var srcFile = TranslatorFile.OpenSrcFile(srcFilepath);
        var translateFile = TranslatorFile.OpenDestFile(srcFile, k_suffixSaveFilepath, ai);


        int totalLine = srcFile.GetTotalLine();
        // load dst file lines
        foreach (var srcLineParserPair in srcFile.m_lineParserMap)
        {
            var srcLineParser = srcLineParserPair.Value;
            var lineIndex = srcLineParser.m_index;
            {
                var dstLineParser = translateFile.TryGetLine(lineIndex);
                if (dstLineParser == null)
                {
                    Console.WriteLine("not found dst line at index: " + lineIndex);
                    continue;
                }

                // you already translate this!
                // just skip it
                if (translateFile.ShouldTranslateText(
                    srcLineParser, dstLineParser) == false)
                    continue;
            }

            // restore first before translate!
            if (translateFile.TryRestoreBackToSource(lineIndex))
            {
                Logger.Log(" -- done restore line back to soruce!");
            }


            int maxRetry = GlobalConfig.MaxTranslateRrtry;
            for (int attemptIndex = 0; attemptIndex < maxRetry; attemptIndex++)
            {
                // save file
                if (saveFileTimer.Elapsed.TotalSeconds > GlobalConfig.SaveFileEveryTime)
                {
                    translateFile.Save();
                    saveFileTimer.Restart();
                }
                LineParser? translateParser;
                {

                    var result = await ai.TryTranslateAsync(
                        srcLineParser.m_text);
                    if (result == null)
                    {
                        Logger.Log([
                            " -- can't translate this line",
                        srcLineParser.m_text,
                        " -- skip it",
                    ]);
                        break;
                    }
                    // parse it
                    translateParser = LineParser.Parse(lineIndex, result);
                    // fix tags first!!
                    if (translateFile.TryRestoreTags(srcLineParser, translateParser,
                            out var newLineRestoreTags))
                    {
                        translateParser = newLineRestoreTags;
                        translateFile.UpdateLineParser(newLineRestoreTags);
                        Logger.Log([
                            " -- restored tags: ",
                        " -- source >> ",
                        srcLineParser.m_raw,
                        " -- translate result >> ",
                        translateParser.m_raw,
                    ]);
                    }
                }

                // retry translate if result word from ai correct
                if (translateFile.ShouldTranslateText(
                        srcLineParser, translateParser))
                {
                    Logger.Log([
                        $" -- retry translate again",
                        $" -- attemp: {attemptIndex + 1}/{maxRetry}",
                        $" -- line index: {lineIndex}/{totalLine}",
                        $" -- source text >> ",
                        srcLineParser.m_text,
                        $" -- translate result >> ",
                        translateParser.m_text,
                    ]);

                    continue;
                }

                // replace it
                Logger.Log([
                    $" -- translated text!",
                    $" -- index   : {lineIndex}/{totalLine}",
                    $" -- src text: {srcLineParser.m_text}",
                    $" -- new text: {translateParser.m_text}",
                    ]);
                translateFile.UpdateLineParser(translateParser);

                // next line!
                break;
            }
        }
        translateFile.Save();
        Console.WriteLine("successfully translate all!");
    }
}