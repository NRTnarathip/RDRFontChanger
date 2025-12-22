using System;
using System.Collections.Generic;
using System.Reflection.Metadata.Ecma335;
using System.Security.Permissions;
using System.Text;
using System.Text.RegularExpressions;

public sealed class LineParser
{
    public enum TextType : int
    {
        HTMLTag,
        ColorTag,
        Placeholder,
        AssetPath,
        Text,
    }

    public readonly string m_prefix;
    public readonly string m_raw;
    public readonly string m_text;
    public readonly int m_index = -1;
    public readonly List<string> textSplits = new();
    public readonly List<TextType> textTypeSplits = new();
    // don't keep text
    public readonly List<string> m_tagOrSymbolList = new();
    public readonly bool isPureText;
    public readonly bool isPureSingleSymbol;

    public LineParser(string line)
    {
        this.m_raw = line = line.Trim();
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
        this.m_prefix = line.Substring(0, dashIndex + 2);
        this.m_text = line.Substring(dashIndex + 1).Trim();
        this.m_index = index;

        var currentText = m_text;
        while (currentText.Length > 0)
        {
            int moveNext = 1;
            var c = currentText[0];

            // find html tag first!
            if (c == '<')
            {
                if (TryParseHTMLTag(currentText,
                    out var content, out var beginTag, out var endTag))
                {
                    //Console.WriteLine($"found tag: {beginTag}{content}{endTag}");
                    moveNext = content.Length + beginTag.Length + endTag.Length;
                    // check if it's color tag
                    if (IsColorTag(beginTag, out var colorName))
                    {
                        // Console.WriteLine($"found is color!, content: {content}, name: {colorName}");
                        MarkText(beginTag, TextType.ColorTag);
                        MarkText(content, TextType.Text);
                        MarkText(endTag, TextType.ColorTag);
                    }
                    else
                    {
                        MarkText(content, TextType.HTMLTag);
                    }
                }
            }

            // like {@RADIAL_MENU.SHOW_HIDE:PENDING}
            else if (c == '{')
            {
                if (TryParsePlaceholder(currentText,
                    out var content, out var beginIndex))
                {
                    //Console.WriteLine($"found ui prompt tag: {content}");
                    moveNext = beginIndex + content.Length;
                    MarkText(content, TextType.Placeholder);
                }
            }

            // like $/content/scripting/DesignerDefined/SocialClub/sc_example_template
            else if (currentText.StartsWith("$/"))
            {
                moveNext = -1;
                MarkText(currentText, TextType.AssetPath);
            }

            // unknow text content
            else
            {
                // try find first any tag
                var firstAnyTagIndex = Regex.Match(currentText, "[<{]");
                if (firstAnyTagIndex.Success)
                {
                    var content = currentText.Substring(0, firstAnyTagIndex.Index);
                    moveNext = content.Length;
                    MarkText(content, TextType.Text);
                    //Console.WriteLine($"found content text: {content}");
                }
                else
                {
                    // all current text is pure text
                    moveNext = currentText.Length;
                    MarkText(currentText, TextType.Text);
                    // Console.WriteLine($"found pure text: {currentText}");
                }
            }

            if (moveNext <= 0
                || moveNext >= currentText.Length)
                break;
            // cut next string
            currentText = currentText.Substring(moveNext);
        }

        // helper
        foreach (var type in textTypeSplits)
        {
            if (type != TextType.Text)
            {
                isPureText = false;
                break;
            }
        }

        isPureSingleSymbol = textTypeSplits.Count == 1
                && textTypeSplits[0] != TextType.Text;
    }
    public static LineParser New(int i, string text)
    {
        return new LineParser(MakeLine(i, text));
    }
    public static string MakeLine(int i, string text)
    {
        return $"[{i}] - {text}";
    }
    void MarkText(string text, TextType type)
    {
        this.textSplits.Add(text);
        this.textTypeSplits.Add(type);
        if (type != TextType.Text)
            m_tagOrSymbolList.Add(text);
    }

    static readonly HashSet<string> ColorBeginTags = [
        "<red>", "<blue>", "<green>", "<orange>",
        "<yellow>", "<green>", "<purple>", "<brown>",
        "<sepia>", "<gray>", "<purple>", "<brow>",
    ];

    public static bool IsColorTag(string text, out string colorName)
    {
        colorName = "";
        // min len
        if (text.Length < 5)
            return false;

        var beginTag = TryFindFirstTag(text, ['<', '>'],
                out var begin, out var end);
        if (ColorBeginTags.Contains(beginTag))
            colorName = beginTag.Substring(1, beginTag.Length - 2);

        return colorName.Length != 0;
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


    internal bool IsSameTags(LineParser target)
    {
        // just pure text, don't check tags
        if (target.isPureText && this.isPureText)
            return true;

        // same tags count
        if (target.m_tagOrSymbolList.Count == this.m_tagOrSymbolList.Count)
        {
            for (int i = 0; i < target.m_tagOrSymbolList.Count; i++)
            {
                // not same!!
                if (target.m_tagOrSymbolList[i] != this.m_tagOrSymbolList[i])
                    return false;
            }

            // same here
            return true;
        }


        // not match tags
        return false;
    }
}
