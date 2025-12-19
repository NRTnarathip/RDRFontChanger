using OpenAI;
using OpenAI.Chat;
using System.ClientModel;
using System.Diagnostics;
using System.Text.RegularExpressions;

var options = new OpenAIClientOptions
{
    Endpoint = new Uri("http://localhost:1234/v1")
};

ChatClient client = new ChatClient("typhoon-translate-4b",
    new ApiKeyCredential("aweasd"), options);

var dir = "D:\\SteamLibrary\\steamapps\\common\\Red Dead Redemption\\mods\\localize";
var filename = "interface_win32.txt";
var srcFilePath = Path.Combine(dir, filename);
var saveFilePath = Path.Combine(dir, filename.Replace(".txt", "@thai-ai.txt"));
if (File.Exists(saveFilePath) == false)
    File.Copy(srcFilePath, saveFilePath);

Stopwatch saveFileTimer = new Stopwatch();
saveFileTimer.Start();
int saveFileEverySeconds = 5;
var writeLines = File.ReadAllLines(saveFilePath);
int totalLine = writeLines.Length;
for (int lineIndex = 0; lineIndex < totalLine; lineIndex++)
{
    var line = writeLines[lineIndex];
    if (line.Length == 0)
        continue;

    // already translate it
    bool hasThai = Regex.IsMatch(line, @"[\u0E00-\u0E7F]");
    if (hasThai)
        continue;

    int openBracket = line.IndexOf('[');
    int closeBracket = line.IndexOf(']');
    int dashIndex = line.IndexOf('-');
    if (dashIndex == -1)
        continue;

    string prefix = line.Substring(0, dashIndex + 1);
    string text = line.Substring(dashIndex + 1).Trim();

    // $/content/scripting/DesignerDefined/SocialClub/sc_challenge_02
    if (text.StartsWith("$/"))
    {
        Console.WriteLine("skip: " + line);
        continue;
    }

    string textPartPattern = @"(<[^>]+>|\{[^}]+\})";
    string[] textSplits = Regex.Split(
        text, textPartPattern)
          .Where(s => !string.IsNullOrEmpty(s) && !Regex.IsMatch(s, @"^\w+$")).ToArray();

    // check if found any string
    // if not found we should stop it!
    bool foundAnyWord = false;
    foreach (string p in textSplits)
    {
        var part = p.Trim();
        // like "  "
        if (part.Length == 0)
            continue;

        // such as:  <A>  {@UI.xxx}
        if (part.StartsWith("<") || part.StartsWith("{"))
            continue;

        foundAnyWord = true;
        break;
    }

    if (!foundAnyWord)
    {
        Console.WriteLine($"skip: {line}");
        continue;
    }

    // try translate this line
    string translateText = "";
    while (true)
    {
        translateText = await TranslateTextAsync(client, text);
        string[] translateTextSplits = translateText.Split(
            ["\r\n", "\r", "\n"], StringSplitOptions.None);
        Console.WriteLine("retry...");
        // only 1 line!
        if (translateTextSplits.Length != 1
            || translateText.Contains("ภาษาไทย"))
        {
            Console.WriteLine("look like your AI result is incorrect");
            Console.WriteLine($"result: {translateText}");
            translateText = ""; //clear
            continue;
        }

        break;
    }

    if (translateText.Length == 0)
    {
        await EjectModelAsync();
        Console.WriteLine("stop translate!");
        break;
    }

    string indexStr = line.Substring(openBracket + 1, closeBracket - openBracket - 1);
    int index = int.Parse(indexStr);
    var newLine = $"[{index}] - {translateText}";
    writeLines[lineIndex] = newLine;
    Console.WriteLine($"write line: " + newLine);

    if (saveFileTimer.Elapsed.TotalSeconds >= saveFileEverySeconds)
    {
        Console.WriteLine($"progress line {lineIndex + 1} / {totalLine} total");
        Console.WriteLine("try saving file...");
        File.WriteAllLines(saveFilePath, writeLines);
        Console.WriteLine("saved file!");
        saveFileTimer.Restart(); //reset it!
    }
}

File.WriteAllLines(saveFilePath, writeLines);
Console.WriteLine("success translate all lines!");
Console.Read();

async Task EjectModelAsync()
{
    Console.WriteLine("Try Eject model...");
    using (var client = new HttpClient())
    {
        var requestUri = "http://localhost:1234/v1/models/eject";
        try
        {
            var response = await client.PostAsync(requestUri, null);
            if (response.IsSuccessStatusCode)
            {
                Console.WriteLine("Model ejected successfully.");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
}

async Task<string> TranslateTextAsync(ChatClient client, string text)
{
    List<ChatMessage> messages = [
        new SystemChatMessage($"Translate to Thai. " +
            $"Provide ONLY the translated text without explanations or quotes. " +
            $"Output only 1 line. "),
        new UserChatMessage(text)
    ];

    try
    {
        ChatCompletion completion = await client.CompleteChatAsync(messages);
        return completion.Content[0].Text.Trim();
    }
    catch (Exception ex)
    {
        return $"[Error: {ex.Message}]";
    }
}