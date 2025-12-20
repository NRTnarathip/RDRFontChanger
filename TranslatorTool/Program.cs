using System.Diagnostics;

internal class Program
{
    private static async Task Main(string[] args)
    {
        if (args.Length == 0)
        {
#if DEBUG
            args = ["interface_win32.txt"];
#endif
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

        // ready to load
        var srcFile = TranslatorFile.OpenSrcFile(srcFilepath);
        var thaiTranslatorFile = TranslatorFile.OpenDestFile(srcFile, k_suffixSaveFilepath);

        // setup AI Translator Tool
        var beginLineIndex = 0;
        var translatorTool = new ThaiTranslator();

        // load dst file lines
        foreach (var srcLineParserPair in srcFile.m_lineParserMap)
        {
            var srcLineParser = srcLineParserPair.Value;
            var index = srcLineParser.m_index;

            if (!thaiTranslatorFile.m_lineParserMap.TryGetValue(index,
                out LineParser? dstLineParser))
            {
                Console.WriteLine($"not found src: {srcLineParser.m_raw} at dst file!");
                continue;
            }

            // assert should you translate this source line??
            if (srcLineParser.isPureSingleSymbol)
            {
                Console.WriteLine($"skip line: {srcLineParser.m_raw}");
                continue;
            }

            // check if this line is translate yet??
            if (translatorTool.IsTranslateYet(
                srcLineParser, dstLineParser))
            {
                Console.WriteLine($"already translated: {dstLineParser.m_raw}");
                continue;
            }

            var translateResult = await translatorTool.TryTranslateAsync(
                srcLineParser.m_text);

            if (translateResult == null)
            {
                Console.WriteLine("can't translate this line, skip it!");
                continue;
            }

            // check if tags it valid same lik source
            var translateResultParser = LineParser.New(index, translateResult);
            if (translateResultParser.IsSameTags(srcLineParser) == false)
            {
                Console.WriteLine("result translate tags it not same source!");
                Console.WriteLine($"result: {translateResult}");
                // restore back!!
                Console.WriteLine($"try restore back: {srcLineParser.m_raw}");
                thaiTranslatorFile.SetLineParser(srcLineParser);
                continue;
            }


            // replace it
            Console.WriteLine($"translate text: [{index}] - {translateResult}");
            thaiTranslatorFile.SetLineParser(translateResultParser);

            // save file
            if (saveFileTimer.Elapsed.TotalSeconds > saveFileEeverySeconds)
            {
                thaiTranslatorFile.Save();
                Console.WriteLine($"progress {index}/{thaiTranslatorFile.m_linesReadonly.Length} total");
                saveFileTimer.Restart();
            }
        }
        Console.WriteLine("successfully translate all lines!");
        thaiTranslatorFile.Save();
        Console.Read();
    }
}