using System.Xml;

public class TranslatorFile
{
    public readonly string m_path;

    // dont edit data
    public readonly string[] m_linesReadonly;

    // repalce text here
    public readonly Dictionary<int, string> m_lineStringMap = new();
    public readonly Dictionary<int, LineParser> m_lineParserMap = new();

    private readonly TranslatorFile? m_srcFile;
    public bool isSourceFile => m_srcFile == null;
    public bool isTranslateFile => m_srcFile != null;
    private AITranslatorAbstract? m_ai;

    TranslatorFile(string path, TranslatorFile? srcFile = null,
        AITranslatorAbstract? ai = null)
    {
        if (path.EndsWith(".txt") == false)
            throw new Exception("Translate file must be .txt");

        this.m_path = path;
        this.m_srcFile = srcFile;
        this.m_ai = ai;

        Console.WriteLine("try to load translate file: " + path);

        m_linesReadonly = File.ReadAllLines(path);
        foreach (var line in m_linesReadonly)
        {
            var parser = new LineParser(line);
            SetLineParser(parser);
        }
        Console.WriteLine("total lines: " + GetTotalLineParser());
        LogInfo();
    }

    int GetTotalLineParser() => m_lineParserMap.Count;

    public static TranslatorFile OpenSrcFile(string path)
    {
        return new TranslatorFile(path, null);
    }

    public static TranslatorFile OpenDestFile(
        TranslatorFile srcFile,
        string translateFileSuffix,
        AITranslatorAbstract ai)
    {
        if (!srcFile.isSourceFile)
            throw new Exception("param srcFile is not source file!");

        var dstPath = srcFile.m_path.Replace(".txt", translateFileSuffix);
        // create new!
        if (File.Exists(dstPath) == false)
            File.Copy(srcFile.m_path, dstPath);

        return new TranslatorFile(dstPath, srcFile, ai: ai);
    }

    public void Save()
    {
        if (isSourceFile)
        {
            Console.WriteLine("can't save at source file!!");
            return;
        }

        var savePath = this.m_path;
        Console.WriteLine("saving file: " + savePath);
        var lines = new List<string>();
        foreach (var item in m_lineStringMap)
        {
            var line = item.Value;
            var index = item.Key;
            lines.Add($"[{index}] - {line}");
        }
        File.WriteAllLines(savePath, lines);
        Console.WriteLine("saved file : " + savePath);
        LogInfo();
    }

    public void SetLineParser(LineParser parser)
    {
        m_lineStringMap[parser.m_index] = parser.m_text;
        m_lineParserMap[parser.m_index] = parser;
    }

    public LineParser? TryGetLine(int index)
    {
        m_lineParserMap.TryGetValue(index, out var line);
        return line;
    }

    public int GetTranslateProgress()
    {
        if (isSourceFile)
            return GetTotalLineParser();

        if (m_ai == null)
            throw new Exception("AI Translator is null!");

        int progress = 0;
        foreach (var item in m_lineParserMap)
        {
            int index = item.Key;
            var thisLine = item.Value;
            var srcLine = m_srcFile.TryGetLine(index);
            if (srcLine == null)
                continue;

            if (ShouldTranslateText(srcLine, thisLine) == false)
                progress++;
        }

        return progress;
    }

    public void LogInfo()
    {
        Console.WriteLine("================================");
        Console.WriteLine("[ File Info ]");
        Console.WriteLine($"file path: {m_path}");
        int total = GetTotalLineParser();
        Console.WriteLine($"total lines: {total}");
        if (this.isTranslateFile)
        {
            int progress = GetTranslateProgress();
            Console.WriteLine($"progress: {progress} / {total} total");
        }
        Console.WriteLine("================================");
        Console.WriteLine();
        Console.WriteLine();
    }

    public bool ShouldTranslateText(LineParser? src, LineParser? dst)
    {
        if (isSourceFile)
            throw new Exception("can't call on source file!");

        if (src == null || dst == null)
            return false;

        if (src.isPureSingleSymbol)
            return false;


        if (src.m_index != dst.m_index)
        {
            Console.WriteLine($"src index: {src.m_index} != dst index: {dst.m_index}!");
            return false;
        }

        // assert should you translate this source line??
        if (src.isPureSingleSymbol)
        {
            Console.WriteLine($"skip line: {src.m_raw}");
            return false;
        }

        // last check if already translate
        bool translated = m_ai.IsTranslateYet(src, dst);
        if (translated)
            return false;


        return true;
    }
}
