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
    public static AITranslatorAbstract Instance { get; private set; }
    public AITranslatorAbstract()
    {
        Instance = this;

        var clientOoptions = new OpenAIClientOptions
        {
            Endpoint = new Uri("http://localhost:1234/v1")
        };

        var modelname = GetAIModelName();
        this.client = new ChatClient(modelname,
            new ApiKeyCredential("aweasd"), clientOoptions);

        var chatOptions = GetChatCompletionOptions();
        Logger.Log([
            $" -- ai model: {modelname}",
            $" -- system prompt: {GetSystemPrompt()}",
            $" -- Temperature: {chatOptions.Temperature}",
        ]);
    }
    public string GetAIModelName() => GlobalConfig.AIModel;
    public string GetSystemPrompt() => GlobalConfig.Prompt;

    readonly string[] k_lineSeparators = { Environment.NewLine, "\r", "\n" };
    public async Task<string?> TryTranslateAsync(string srcText)
    {
        var maxRetry = GlobalConfig.MaxTranslateRrtry;
        for (int i = 0; i < maxRetry; i++)
        {
            var result = await TranslateTextAsync(srcText);
            var resultLines = result.Split(k_lineSeparators,
                StringSplitOptions.None);

            // check validate
            if (result.Length > 0 && resultLines.Length == 1)
                return result;

            Logger.Log([
                " -- translate incorrect result >> ",
                result,
                $" -- attempt: {i+ 1}/{maxRetry}",
                $" -- retry translate again, src text >>",
                srcText,
            ]);
        }


        return null;
    }
    async Task<string> TranslateTextAsync(string srcText)
    {
        List<ChatMessage> messages = [
            new SystemChatMessage(GetSystemPrompt()),
            new UserChatMessage(srcText)
        ];

        var options = GetChatCompletionOptions();

        try
        {
            ChatCompletion completion = await this.client.CompleteChatAsync(messages, options);
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
    public abstract ChatCompletionOptions GetChatCompletionOptions();
    public abstract bool ShouldTranslateThis(LineParser src, LineParser dst);
}
