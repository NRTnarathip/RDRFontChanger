using OpenAI;
using OpenAI.Chat;
using System;
using System.ClientModel;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using System.Text.RegularExpressions;
using TranslatorTool;

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

        var modelname = GetAIModelName();
        this.client = new ChatClient(modelname,
            new ApiKeyCredential("aweasd"), options);
        Logger.Log([
            $" -- ai model: {modelname}",
            $" -- system prompt: {GetSystemPrompt()}",
        ]);
    }
    public abstract string GetAIModelName();

    readonly string[] k_lineSeparators = { Environment.NewLine, "\r", "\n" };
    public async Task<string?> TryTranslateAsync(string srcText)
    {
        for (int i = 0; i < m_maxRetryCount; i++)
        {
            var result = await TranslateTextAsync(srcText);
            var resultLines = result.Split(k_lineSeparators,
                StringSplitOptions.None);

            // check validate
            if (result.Length > 0 && resultLines.Length == 1)
            {
                return result;
            }
            Logger.Log([
                " -- translate incorrect result >> ",
                result,
                $" -- retry translate again: {srcText}",
            ]);
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
    async Task<string> TranslateTextAsync(string srcText)
    {
        List<ChatMessage> messages = [
            new SystemChatMessage(GetSystemPrompt()),
            new UserChatMessage(srcText)
        ];

        try
        {
            ChatCompletion completion = await this.client.CompleteChatAsync(messages);
            string result = completion.Content[0].Text.Trim();
            PostTranslateTextAsync(srcText, ref result);
            return result;
        }
        catch (Exception ex)
        {
            return $"[Error: {ex.Message}]";
        }
    }

    public virtual void PostTranslateTextAsync(string original, ref string text) { }
    public abstract bool ShouldTranslateThis(LineParser src, LineParser dst);
    public abstract String GetSystemPrompt();
}
