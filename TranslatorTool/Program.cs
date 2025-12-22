using System.Diagnostics;
using TranslatorTool;

internal class Program
{
    private static async Task Main(string[] args)
    {
        if (args.Length == 0)
        {
            Console.WriteLine("Please put source file path");
            Console.Read();
            return;
        }

        var srcFilepath = args[0];
        if (srcFilepath.EndsWith(".txt") == false)
        {
            Console.WriteLine("File name must be .txt!");
            Console.Read();
            return;
        }

        Stopwatch saveFileTimer = Stopwatch.StartNew();
        float saveFileEeverySeconds = 5;

        const string k_suffixSaveFilepath = "@ai_translate.txt";
        var saveFilePath = srcFilepath.Replace(".txt", k_suffixSaveFilepath);
        // create it!
        if (!File.Exists(saveFilePath))
            File.Copy(srcFilepath, saveFilePath);

        // setup AI Translator Tool
        var beginLineIndex = 0;
        var ai = new ThaiAITranslator();

        // ready to load
        var srcFile = TranslatorFile.OpenSrcFile(srcFilepath);
        var translateFile = TranslatorFile.OpenDestFile(srcFile, k_suffixSaveFilepath, ai);


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

            while (true)
            {
                // save file
                if (saveFileTimer.Elapsed.TotalSeconds > saveFileEeverySeconds)
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
                        $" -- retry translate again...",
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
                    $" -- index   : {index}",
                    $" -- src text: {srcLineParser.m_text}",
                    $" -- result  : {result}",
                    ]);
                translateFile.UpdateLineParser(resultParser);

                // next line!
                break;
            }
        }
        Console.WriteLine("successfully translate all lines!");
        translateFile.Save();
        Console.Read();
    }
}