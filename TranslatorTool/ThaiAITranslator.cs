using System.Text.RegularExpressions;

public sealed class ThaiAITranslator : AITranslatorAbstract
{
    public static bool HasThai(string input)
    {
        return Regex.IsMatch(input, @"[\u0E00-\u0E7F]");
    }

    public override string GetSystemPrompt()
    {
        return $"Translate to Thai. " +
                   "ห้ามใช้คำ ครับ ค่ะ " +
                   "ใช้คำนามเช่น คุณ ข้า เจ้า ถ้าหากคุณไม่เข้าใจบริบทว่าเพศใดพูด " +
                   $"Provide ONLY the translated text without explanations or quotes. " +
                   $"Output only 1 line. ";
    }

    public override bool IsTranslateYet(LineParser src, LineParser dst)
    {
        return HasThai(dst.m_text);
    }
}
