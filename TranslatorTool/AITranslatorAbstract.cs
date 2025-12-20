using OpenAI;
using OpenAI.Chat;
using System;
using System.ClientModel;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;

public abstract class AITranslatorAbstract
{
    public readonly ChatClient client;
    int m_maxRetryCount = 3;
    public int MaxRetryCount
    {
        get => m_maxRetryCount;
        set
        {
            if (value <= 0)
                m_maxRetryCount = 3;
            else
                m_maxRetryCount = value;
        }
    }
    public static AITranslatorAbstract Instance { get; private set; }
    public AITranslatorAbstract()
    {
        Instance = this;

        var options = new OpenAIClientOptions
        {
            Endpoint = new Uri("http://localhost:1234/v1")
        };

        this.client = new ChatClient("typhoon-translate-4b",
            new ApiKeyCredential("aweasd"), options);
    }

    readonly string[] k_lineSeparators = { Environment.NewLine, "\r", "\n" };
    public async Task<string?> TryTranslateAsync(string srcText)
    {
        for (int i = 0; i < m_maxRetryCount; i++)
        {
            var result = await TranslateTextAsync(srcText);
            var resultLines = result.Split(k_lineSeparators,
                StringSplitOptions.None);

            // check validate
            if (result.Length > 0
                && resultLines.Length == 1)
            {
                return result;
            }
            Console.WriteLine($"result translate incorrect: {result}");
            Console.WriteLine($"retry translate source: {srcText}");
        }
        return null;
    }

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
    async Task<string> TranslateTextAsync(string text)
    {
        List<ChatMessage> messages = [
            new SystemChatMessage($"Translate to Thai. " +
        $"Provide ONLY the translated text without explanations or quotes. " +
        $"Output only 1 line. "),
    new UserChatMessage(text)
        ];

        try
        {
            ChatCompletion completion = await this.client.CompleteChatAsync(messages);
            return completion.Content[0].Text.Trim();
        }
        catch (Exception ex)
        {
            return $"[Error: {ex.Message}]";
        }
    }

    public abstract bool IsTranslateYet(LineParser src, LineParser dst);
}
