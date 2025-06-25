using UnrealBuildTool;

public class PlafCore : ModuleRules
{
	public PlafCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "EnhancedInput", "GameplayAbilities", "GameplayTasks", "GameplayTags", "UMG" });
		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
