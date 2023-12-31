// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MeleeBattler : ModuleRules
{
	public MeleeBattler(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","GameplayTags", "GameplayAbilities","GameplayTasks" });
		
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
        
        PrivateIncludePaths.AddRange(new string[] { Name });

	}
}
