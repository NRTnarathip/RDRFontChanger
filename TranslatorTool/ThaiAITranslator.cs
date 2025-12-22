using OpenAI.Chat;
using System.Text.RegularExpressions;
using TranslatorTool;

public sealed class ThaiAITranslator : AITranslatorAbstract
{
    public override ChatCompletionOptions GetChatCompletionOptions()
    {
        return new ChatCompletionOptions
        {
            MaxOutputTokenCount = 256,
            Temperature = GlobalConfig.Temperature,
            StopSequences = { "</end>", "\n\n" }
        };
    }

    public static bool IsThaiWord(string input)
    {
        return Regex.IsMatch(input, @"[\u0E00-\u0E7F]");
    }
    static readonly string[] thaiWordBlacklistAndRemove = {
        "ค่ะ", "ครับ",
    };
    public override bool ShouldTranslateThis(LineParser src, LineParser dst)
    {
        var text = dst.m_text.Trim();
        // empty
        if (text.Length == 0)
            return true;

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
        }

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
