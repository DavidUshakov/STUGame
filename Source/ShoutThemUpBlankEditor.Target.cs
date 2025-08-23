// DU INC

using UnrealBuildTool;
using System.Collections.Generic;

public class ShoutThemUpBlankEditorTarget : TargetRules
{
	public ShoutThemUpBlankEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "ShoutThemUpBlank" } );
	}
}
