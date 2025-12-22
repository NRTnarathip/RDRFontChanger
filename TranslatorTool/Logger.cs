using System;
using System.Collections.Generic;
using System.Text;

namespace TranslatorTool;

public static class Logger
{
    public static void Log(string[] texts)
    {
        Long();
        foreach (var t in texts)
        {
            Console.WriteLine(t);
        }
        Long();
    }
    public static void Log(string text)
    {
        Console.WriteLine(text);
    }

    internal static void Long()
    {
        Console.WriteLine("================================================================");
    }
}
