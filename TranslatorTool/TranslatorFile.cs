using System.Xml;
using TranslatorTool;

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
            UpdateLineParser(parser);
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

    int lastSaveUpdateLineCounter = 0;
    public void Save()
    {
        if (isSourceFile)
        {
            Console.WriteLine("can't save at source file!!");
            return;
        }

        // check if any line update
        if (lastSaveUpdateLineCounter == updateLineCounter)
            return;
        lastSaveUpdateLineCounter = updateLineCounter;

        var savePath = this.m_path;
        Console.WriteLine(" -- saving file: " + savePath);
        var lines = new List<string>();
        foreach (var item in m_lineStringMap)
        {
            var line = item.Value;
            var index = item.Key;
            lines.Add($"[{index}] - {line}");
        }
        File.WriteAllLines(savePath, lines);
        Console.WriteLine(" -- saved file : " + savePath);
        LogInfo();
    }

    public int updateLineCounter = 0;
    public void UpdateLineParser(LineParser _parser)
    {
        var cloneParser = _parser.Clone();
        m_lineStringMap[cloneParser.m_index] = cloneParser.m_text;
        m_lineParserMap[cloneParser.m_index] = cloneParser;
        updateLineCounter++;
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
        Logger.Long();
        Console.WriteLine("[ File Info ]");
        Console.WriteLine($" -- file path: {m_path}");
        int total = GetTotalLineParser();
        Console.WriteLine($" -- total lines: {total}");
        if (this.isTranslateFile)
        {
            int progress = GetTranslateProgress();
            Console.WriteLine($" -- progress: {progress} / {total} total");
        }
        Logger.Long();
        Console.WriteLine();
    }

    public bool ShouldTranslateText(LineParser? src, LineParser? dst)
    {
        if (isSourceFile)
            throw new Exception("can't call on source file!");

        if (src == null || dst == null)
            return false;

        if (src.m_isPureSingleSymbol)
            return false;


        if (src.m_index != dst.m_index)
        {
            Console.WriteLine($"src index: {src.m_index} != dst index: {dst.m_index}!");
            return false;
        }

        // tags is not same??
        if (src.IsSameTags(dst) == false)
        {
            //Console.WriteLine("tag src != dst, so should translate this!");
            //Console.WriteLine("src raw: " + src.m_raw);
            //Console.WriteLine("dst raw: " + dst.m_raw);
            return true;
        }

        // last check if already translate
        bool aiShouldTranslateThis = m_ai.ShouldTranslateThis(src, dst);
        if (!aiShouldTranslateThis)
            return false;


        return true;
    }

    internal int GetTotalLine()
    {
        return m_lineParserMap.Count;
    }
    public bool TryRestoreBackToSource(int index)
    {
        if (!isSourceFile)
            return false;

        var srcLineParser = m_srcFile.TryGetLine(index);
        if (srcLineParser == null)
            return false;

        var dstLineParser = this.TryGetLine(index);
        if (dstLineParser == null)
            return false;

        if (dstLineParser.m_text != srcLineParser.m_text)
            UpdateLineParser(srcLineParser);

        return true;
    }

    public bool TryGetLine(int index, out LineParser? srcLine, out LineParser? translateLine)
    {
        srcLine = translateLine = null;

        var srcLineParser = m_srcFile.TryGetLine(index);
        if (srcLineParser == null)
            return false;

        var dstLineParser = this.TryGetLine(index);
        if (dstLineParser == null)
            return false;

        srcLine = srcLineParser;
        translateLine = dstLineParser;
        return true;
    }

    public bool TryRestoreTags(LineParser? src, LineParser? dst, out LineParser newLine)
    {
        newLine = null;

        if (src == null || dst == null)
            return false;

        if (src.IsSameTags(dst))
            return false;

        int restoreTagCount = 0;
        string newLineText = dst.m_text;
        // Console.WriteLine("src tags: " + src.m_tagOrSymbolList.Count);
        // Console.WriteLine("dst tags: " + dst.m_tagOrSymbolList.Count);
        if (src.m_tagOrSymbolList.Count != dst.m_tagOrSymbolList.Count)
        {
            // Console.WriteLine("can't restore cause tag count are not same!");
            return false;
        }

        for (int i = 0; i < src.m_tagOrSymbolList.Count; i++)
        {
            //    Console.WriteLine($"try get tag: {i}");
            var srcTag = src.m_tagOrSymbolList[i];
            var srcTagType = src.m_tagTypeList[i];

            var dstTag = dst.m_tagOrSymbolList[i];
            var dstTagType = dst.m_tagTypeList[i];

            // check if tag it's same type
            if (srcTag != dstTag && srcTagType == dstTagType)
            {
                // restore tag
                newLineText = newLineText.Replace(dstTag, srcTag);
                restoreTagCount++;
            }
        }

        newLine = LineParser.Parse(dst.m_index, newLineText);
        return restoreTagCount > 0;
    }
}
