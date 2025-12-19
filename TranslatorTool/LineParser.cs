using System;
using System.Collections.Generic;
using System.Reflection.Metadata.Ecma335;
using System.Security.Permissions;
using System.Text;
using System.Text.RegularExpressions;

namespace TranslatorTool;

public sealed class LineParser
{
    public enum TextType : int
    {
        HTMLTag,
        Placeholder,
        Text,
    }
    public readonly string m_prefix;
    public readonly string m_text;
    public readonly int m_index = -1;
    public readonly List<string> textSplits = new();
    public readonly List<TextType> textTypeSplits = new();
    public readonly bool isPureText;
    public readonly bool isPureSingleSymbol;

    public LineParser(string line)
    {
        line = line.Trim();
        // assert check!
        int openBracket = line.IndexOf('[');
        int closeBracket = line.IndexOf(']');
        int dashIndex = line.IndexOf('-');
        if (dashIndex == -1)
            return;

        bool indexParseCorrect = int.TryParse(line.Substring(
            openBracket + 1,
            closeBracket - openBracket - 1),
            out int index) && index >= 0;
        if (!indexParseCorrect)
        {
            return;
        }

        // ready!
        this.m_prefix = line.Substring(0, dashIndex + 1);
        this.m_text = line.Substring(dashIndex + 1).Trim();
        this.m_index = index;

        Console.WriteLine("parse line: " + line);

        // try parse tag symbol
        if (IsAnyTagSymbol(m_text))
        {
            var currentText = m_text;
            while (currentText.Length > 0)
            {
                int moveNext = 1;
                // like <A> Hello World  </A>
                var c = currentText[0];
                // find html tag first!
                if (c == '<')
                {
                    if (TryParseHTMLTag(currentText,
                        out var content, out var beginTag, out var endTag))
                    {
                        Console.WriteLine($"found tag: {beginTag}{content}{endTag}");
                        moveNext = content.Length + beginTag.Length + endTag.Length;
                        MarkText(content, TextType.HTMLTag);
                    }
                }
                // like {@RADIAL_MENU.SHOW_HIDE:PENDING}
                else if (c == '{')
                {
                    if (TryParsePlaceholder(currentText,
                        out var content, out var beginIndex))
                    {
                        Console.WriteLine($"found ui prompt tag: {content}");
                        moveNext = beginIndex + content.Length;
                        MarkText(content, TextType.Placeholder);
                    }
                }
                // normal text content
                else
                {
                    var firstAnyTagIndex = Regex.Match(currentText, "[<{]");
                    if (firstAnyTagIndex.Success)
                    {
                        var content = currentText.Substring(0, firstAnyTagIndex.Index);
                        moveNext = content.Length;
                        MarkText(content, TextType.Text);
                        Console.WriteLine($"found content text: {content}");
                    }
                    else
                    {
                        // all current text is pure text
                        moveNext = currentText.Length;
                        MarkText(currentText, TextType.Text);
                        Console.WriteLine($"found pure text: {currentText}");
                    }
                }

                // Console.WriteLine("move next: " + moveNext);
                if (moveNext >= currentText.Length)
                    break;
                currentText = currentText.Substring(moveNext);
            }
        }

        // helper
        isPureText = true;
        foreach (var str in textTypeSplits)
        {
            if (str != TextType.Text)
                isPureText = false;
        }

        isPureSingleSymbol = textTypeSplits.Count == 1
                && textTypeSplits[0] != TextType.Text;
    }

    void MarkText(string text, TextType type)
    {
        this.textSplits.Add(text);
        this.textTypeSplits.Add(type);
    }

    public static bool TryParsePlaceholder(
        string text,
        out string content,
        out int beginIndex)
    {
        content = "";
        beginIndex = -1;

        //  example
        //  {@RADIAL_MENU.SHOW_HIDE:PENDING}
        //  {0}
        var tag = TryFindFirstTag(text,
            ['{', '}'], out beginIndex, out var endIndex);
        if (tag.Length > 0)
        {
            content = text.Substring(beginIndex, endIndex - beginIndex + 1);
        }

        return content.Length > 0;
    }

    public static bool TryParseHTMLTag(string inputText,
        out string content,
        out string beginTag, out string endTag)
    {
        beginTag = "";
        endTag = "";
        content = "";

        // at lest 3 char like: <A>
        if (inputText.Length < 3)
            return false;

        beginTag = TryFindFirstHTMLTag(inputText, out var beginIndexFirst, out var beginIndexLast);
        if (beginTag.Length == 0)
            return false;

        var nextText = inputText.Substring(beginIndexLast + 1);
        endTag = TryFindFirstHTMLTag(nextText, out var endIndexFirst, out var endIndexLast);
        if (endTag.Length == 0)
            return false;

        content = nextText.Substring(0, endIndexFirst);
        return true;
    }

    public static string TryFindFirstHTMLTag(string text,
            out int beginIndex, out int endIndex)
    {
        return TryFindFirstTag(text, ['<', '>'], out beginIndex, out endIndex);
    }

    public static string TryFindFirstTag(string text,
           char[] tagCarBeginEnd,
           out int beginIndex, out int endIndex)
    {
        beginIndex = endIndex = -1;

        if (tagCarBeginEnd.Length != 2)
            return "";

        beginIndex = text.IndexOf(tagCarBeginEnd[0]);
        endIndex = text.IndexOf(tagCarBeginEnd[1]);
        if (beginIndex == -1 || endIndex == -1
            || endIndex < beginIndex)
            return "";
        return text.Substring(beginIndex, endIndex - beginIndex + 1);
    }

    public static bool IsAnyTagSymbol(string t)
    {
        // <a>WW.XX</a>
        // <0xfcaf17>CHALLENGE:</0x>
        // {0} {@UI.xxx} 
        const string pattern = "[<{]";
        return Regex.IsMatch(t, pattern);
    }
}
