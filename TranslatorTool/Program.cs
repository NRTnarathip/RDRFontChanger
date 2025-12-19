using OpenAI;
using OpenAI.Chat;
using System.ClientModel;
using System.Diagnostics;
using System.Text.RegularExpressions;
using TranslatorTool;

internal class Program
{
    private static async Task Main(string[] args)
    {
        var filename = "interface_win32.txt";
        var lines = File.ReadAllLines(filename);
        foreach (var line in lines)
        {
            var lineParse = new LineParser(line);
            if (lineParse.isPureSingleSymbol)
                Console.WriteLine($"skip this line: {line}, don't translate");
        }
        Console.Read();
    }
}