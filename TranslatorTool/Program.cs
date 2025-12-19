using System.Diagnostics;

internal class Program
{
    public static void SaveToFile(string filename, ref List<string> lines)
    {
        Console.WriteLine("saving file: " + filename);
        File.WriteAllLines(filename, lines);
        Console.WriteLine("saved file : " + filename);
    }

    private static async Task Main(string[] args)
    {
        var filename = "interface_win32.txt";
        var lines = File.ReadAllLines(filename);
        var beginLineIndex = 0;
        var translatorTool = new TranslatorTool();

        List<string> newLines = lines.ToList();
        Stopwatch saveFileTimer = Stopwatch.StartNew();
        float saveFileEeverySeconds = 5;
        var saveFilename = filename.Replace(".txt", "-ai.txt");

        for (int i = beginLineIndex; i < lines.Length; i++)
        {
            var line = lines[i];
            var lineParse = new LineParser(line);
            if (lineParse.isPureSingleSymbol)
            {
                Console.WriteLine($"skip this line: {line}");
                continue;
            }
            var translateText = await translatorTool.TryTranslateAsync(lineParse.m_text);
            Console.WriteLine("translate text: " + translateText);
            newLines[i] = lineParse.m_prefix + translateText;

            // save file
            if (saveFileTimer.Elapsed.TotalSeconds > saveFileEeverySeconds)
            {
                SaveToFile(saveFilename, ref newLines);
                Console.WriteLine($"progress {i}/{lines.Length} total");
                saveFileTimer.Restart();
            }
        }
        Console.WriteLine("successfully translate all lines!");
        SaveToFile(saveFilename, ref newLines);
        Console.Read();
    }
}