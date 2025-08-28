// DU INC

using UnrealBuildTool;

public class ShoutThemUpBlank : ModuleRules
{
    public ShoutThemUpBlank(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] 
        { 
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore", 
            "Niagara",
            "PhysicsCore",
            "GameplayTasks",
            "NavigationSystem"
        });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        PublicIncludePaths.AddRange(new string[] {
        "ShoutThemUpBlank/Public/Player",
        "ShoutThemUpBlank/Public/Dev",
        "ShoutThemUpBlank/Public/Weapon",
        "ShoutThemUpBlank/Public/UI",
        "ShoutThemUpBlank/Public/Components",
        "ShoutThemUpBlank/Public/Animations",
        "ShoutThemUpBlank/Public/Pickups",
        "ShoutThemUpBlank/Public/Weapon/Components",
        "ShoutThemUpBlank/Public/AI",
        "ShoutThemUpBlank/Public/AI/Tasks",
        "ShoutThemUpBlank/Public/AI/Services",
        "ShoutThemUpBlank/Public/AI/EQS",
        "ShoutThemUpBlank/Public/AI/Decorators",
        "ShoutThemUpBlank/Public/Menu",
        "ShoutThemUpBlank/Public/Menu/UI",
        "ShoutThemUpBlank/Public/Sound",
        });
        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
