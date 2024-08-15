class DayZScriptedSettings_Settings
{
	int debug_log_level = 1;
	int environment = 1;

	[NonSerialized()]
	protected bool m_IsLoaded;

	[NonSerialized()]
	string m_ConfigurationFile;

	void DayZScriptedSettings_Settings(string AppName)
	{
		if(GetGame().IsClient()) return;

		string ConfigurationPath = "$profile:ModPath";
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
