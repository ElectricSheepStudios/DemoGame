// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DemoGame : ModuleRules
{
    public DemoGame(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                "DemoGame"
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine", 
                "InputCore",
                "ModularGameplay",
                "ModularGameplayActors",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[] {

            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[] {
            }
        );

        // Generate compile errors if using DrawDebug functions in test/shipping builds.
        PublicDefinitions.Add("SHIPPING_DRAW_DEBUG_ERROR=1");
    }
}
