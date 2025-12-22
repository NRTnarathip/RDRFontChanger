using System.Text.RegularExpressions;
using TranslatorTool;

public sealed class ThaiAITranslator : AITranslatorAbstract
{
    public override string GetAIModelName()
    {
        return "typhoon2.1-gemma3-4b";
        // return "typhoon2.1-gemma3-4b";
    }
    public static bool IsThaiWord(string input)
    {
        return Regex.IsMatch(input, @"[\u0E00-\u0E7F]");
    }

    public override string GetSystemPrompt()
    {
        //string[] p = {$"Translate to Thai.",
        //    $"เก็บประโยคที่มี HTML Tag ใว้ด้วย เช่น <red>บอนนี่</>",
        //    $"ห้ามใช้คำ ครับ ค่ะ",
        //    $"Provide ONLY the translated text without explanations or quotes.",
        //    $"Output only 1 line.",
        //};
        //var line = string.Join(", ", p);
        var line = """
            แปลเป็นภาษาไทยสำหรับเกม
            - ห้ามแก้ / ลบ / ย้าย HTML tag, สี, หรือสัญลักษณ์ UI ใดๆ
            - คง <tag>...</tag> ไว้ตำแหน่งเดิม
            - ภาษาเป็นธรรมชาติแบบเกม
            - ไม่ต้องสุภาพเกิน
            """;
        return line;
    }

    static readonly string[] thaiWordBlacklistAndRemove = {
        "ค่ะ", "ครับ",
    };

    public override bool ShouldTranslateThis(LineParser src, LineParser dst)
    {
        var text = dst.m_text;
        // is eng?
        if (IsThaiWord(text) == false)
            return true;


        // thai word validate check
        foreach (var word in thaiWordBlacklistAndRemove)
        {
            if (text.Contains(word))
                return true;
        }

        return false;
    }

    static readonly string[] delimiters = { Environment.NewLine, "\r", "\n" };

    public override void PostTranslateTextAsync(string srcText, ref string resultTranslate)
    {
        string[] lines = resultTranslate.Split(delimiters, StringSplitOptions.RemoveEmptyEntries);
        if (lines.Length != 1)
        {
            Logger.Log([
                " -- warning you have multiple output! >> ",
                resultTranslate,
                " -- source text >> ",
                srcText,
            ]);
            var lastText = lines.Last();
            if (IsThaiWord(lastText))
            {
                resultTranslate = lastText;
                // remove blacklist word
                foreach (var word in thaiWordBlacklistAndRemove)
                {
                    if (resultTranslate.Contains(word))
                    {
                        resultTranslate = resultTranslate.Replace(word, "");
                        Console.WriteLine($" -- remove word!: {word}");
                    }
                }
            }
        }
    }
}
