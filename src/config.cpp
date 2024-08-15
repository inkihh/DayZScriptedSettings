class CfgPatches
{
	class DayZScriptedSettings
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Scripts",
			"DZ_Data",
			"DZ_Structures"
		};
	};
};

class CfgMods
{
	class DayZScriptedSettings
	{
		dir = "DayZScriptedSettings";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "DayZScriptedSettings";
		credits = "";
		author = "inkihh";
		authorID = "0";
		version = "1";
		extra = 0;
		type = "mod";

		dependencies[] = {
			"Core",
			"Game",
			"World",
			"Mission"
		};

		class defs
		{
			class coreScriptModule
			{
				value = "";
				files[] = {
					"DayZScriptedSettings/scripts/1_Core"
				};
			};

			class gameScriptModule
			{
				value = "";
				files[] = {
					"DayZScriptedSettings/scripts/3_Game"
				};
			};

			class worldScriptModule
			{
				value = "";
				files[] = {
					"DayZScriptedSettings/scripts/4_World"
				};
			};
			
			class missionScriptModule
			{
				value = "";
				files[] = {
					"DayZScriptedSettings/scripts/5_Mission"
				};
			};
		};
	};
};

