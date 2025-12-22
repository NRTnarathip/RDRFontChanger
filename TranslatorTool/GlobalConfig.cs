using Spectre.Console;
using Spectre.Console.Cli;
using System.ComponentModel;

namespace TranslatorTool;

public sealed class GlobalCommand : Command<GlobalCommand.Settings>
{
    public sealed class Settings : CommandSettings
    {
        [Description("source text path")]
        [CommandOption("--input")]
        public string? input { get; init; }

        [Description("AI model nam")]
        [CommandOption("--aimodel")]
        public string? aimodel { get; init; }

        [Description("AI system prompt")]
        [CommandOption("--prompt")]
        public string? prompt { get; init; }

        [CommandOption("--temperature")]
        [DefaultValue(0.2f)]
        public float temperature { get; init; }

        [CommandOption("--max-translate-retry")]
        [DefaultValue(10)]
        public int maxTranslateRetry { get; init; }

        [CommandOption("--savefile_everytime")]
        [DefaultValue(5)]
        public int saveFileEveryTime { get; init; }
    }

    public static Settings settings { get; private set; }
    public override int Execute(CommandContext context, Settings settings, CancellationToken cancellationToken)
    {
        GlobalCommand.settings = settings;
        return 0;
    }
}

internal static class GlobalConfig
{
    public static string InputSourcePath => GlobalCommand.settings.input;
    public static string AIModel => GlobalCommand.settings.aimodel;
    public static string Prompt => GlobalCommand.settings.prompt;
    public static int MaxTranslateRrtry => GlobalCommand.settings.maxTranslateRetry;
    public static int SaveFileEveryTime => GlobalCommand.settings.saveFileEveryTime;
    public static float Temperature => GlobalCommand.settings.temperature;


    internal static void Init(string[] args)
    {
        var app = new CommandApp<GlobalCommand>();
        app.Run(args);
    }
}
