public class TranslatorFile
{
    public readonly string m_path;

    // dont edit data
    public readonly string[] m_linesReadonly;

    // repalce text here
    public readonly Dictionary<int, string> m_lineMapEdit = new();
    public readonly Dictionary<int, LineParser> m_lineParserMap = new();

    private readonly bool m_isSourceFile;

    TranslatorFile(string path, bool isSourceFile)
    {
        if (path.EndsWith(".txt") == false)
            throw new Exception("Translate file must be .txt");

        this.m_path = path;
        this.m_isSourceFile = isSourceFile;
        m_linesReadonly = File.ReadAllLines(path);
        foreach (var line in m_linesReadonly)
        {
            var parser = new LineParser(line);
            SetLineParser(parser);
        }
    }
    public static TranslatorFile OpenSrcFile(string path)
    {
        return new TranslatorFile(path, true);
    }

    public static TranslatorFile OpenDestFile(TranslatorFile srcFile, string translateFileSuffix)
    {
        var dstPath = srcFile.m_path.Replace(".txt", translateFileSuffix);
        // create new!
        if (File.Exists(dstPath) == false)
            File.Copy(srcFile.m_path, dstPath);

        return new TranslatorFile(dstPath, false);
    }

    public void Save()
    {
        var savePath = this.m_path;
        Console.WriteLine("saving file: " + savePath);
        var lines = new List<string>();
        foreach (var item in m_lineMapEdit)
        {
            var line = item.Value;
            var index = item.Key;
            lines.Add($"[{index}] - {line}");
        }
        File.WriteAllLines(savePath, lines);
        Console.WriteLine("saved file : " + savePath);
    }

    public void SetLineParser(LineParser parser)
    {
        m_lineMapEdit[parser.m_index] = parser.m_text;
        m_lineParserMap[parser.m_index] = parser;
    }
}
