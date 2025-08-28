// DU INC

using UnrealBuildTool;
using System.Collections.Generic;

public class ShoutThemUpBlankTarget : TargetRules
{
	public ShoutThemUpBlankTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "ShoutThemUpBlank" } );
	}
}
