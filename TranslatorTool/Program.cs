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
            var index = srcLineParser.m_index;
            {
                var dstLineParser = translateFile.TryGetLine(index);
                if (dstLineParser == null)
                {
                    Console.WriteLine("not found dst line at index: " + index);
                    continue;
                }

                // you already translate this!
                // just skip it
                if (translateFile.ShouldTranslateText(
                    srcLineParser, dstLineParser) == false)
                    continue;
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


                var resultParser = LineParser.New(index, result);

                // retry translate if result word from ai correct
                if (translateFile.ShouldTranslateText(
                        srcLineParser, resultParser))
                {
                    Logger.Log([
                        $" -- retry translate again",
                        $" -- attemp: {attemptIndex + 1}/{maxRetry}",
                        $" -- source text >> ",
                        srcLineParser.m_text,
                        $" -- translate result >> ",
                        result,
                    ]);
                    continue;
                }

                // replace it
                Logger.Log([
                    $" -- translated text!",
                    $" -- index   : {index}/{totalLine}",
                    $" -- src text: {srcLineParser.m_text}",
                    $" -- new text: {result}",
                    ]);
                translateFile.UpdateLineParser(resultParser);

                // next line!
                break;
            }
        }
        translateFile.Save();
        Console.WriteLine("successfully translate all!");
    }
}