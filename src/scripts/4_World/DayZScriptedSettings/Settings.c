class DayZScriptedSettings_Settings
{
	int debug_log_level = 1;
	int environment = 1;

	int RemovePredatorMeatPoisoning = false;
	int CanToggleNvgInVehicle = false;
	int DisablePlayerRestraining = false;

	// FutureSixx Addons
	
	bool EnableLeaningWhileSprinting = false;
	bool EnableGasMaskOnlyContaminatedAreas = false;

	// Vehicle Stuff
	bool EnableNVGsInVehicle = false;
	float VehicleCE_FuelMinSpawn = 0.25;
	float VehicleCE_FuelMaxSpawn = 0.75;
	float VehicleCE_CoolantMinSpawn = 0.5;
	float VehicleCE_CoolantMaxSpawn = 1.0;

	// ItemBase Stuff
	bool DisableItemsInCargoDamage = false;
	bool DisableAttachmentItemsDamage = false;

	// End of FutureSixx Addons

	[NonSerialized()]
	protected bool m_IsLoaded;

	[NonSerialized()]
	string m_ConfigurationFile;

	void DayZScriptedSettings_Settings(string AppName)
	{
		if(GetGame().IsClient()) return;

		string ConfigurationPath = "$profile:DayZScriptedSettings";
		MakeDirectory(ConfigurationPath);

		m_ConfigurationFile = ConfigurationPath + "/DayZScriptedSettings.json";
		this.m_IsLoaded = this.Load();
	}

	bool Load()
	{
		if(GetGame().IsClient()) return false;

		if (FileExist(m_ConfigurationFile))
		{
			Print("[DayZScriptedSettings_Settings] Found config file \"" + m_ConfigurationFile + "\"");
			JsonFileLoader<DayZScriptedSettings_Settings>.JsonLoadFile(m_ConfigurationFile, this);
			JsonFileLoader<DayZScriptedSettings_Settings>.JsonSaveFile(m_ConfigurationFile, this);
			return true;
		}

		JsonFileLoader<DayZScriptedSettings_Settings>.JsonSaveFile(m_ConfigurationFile, this);
		return false;
	}

	bool IsLoaded()
	{
		if(GetGame().IsClient()) return false;
		return this.m_IsLoaded;
	}
}
