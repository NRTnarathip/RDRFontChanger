using System.Text.RegularExpressions;

public sealed class ThaiTranslator : AITranslatorAbstract
{
    public static bool HasThai(string input)
    {
        return Regex.IsMatch(input, @"[\u0E00-\u0E7F]");
    }

    public override bool IsTranslateYet(LineParser src, LineParser dst)
    {
        return HasThai(dst.m_text);
    }
}
