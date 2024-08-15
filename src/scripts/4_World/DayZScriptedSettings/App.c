class DayZScriptedSettings_App
{
	string m_Name = "DayZScriptedSettings";
	protected static ref DayZScriptedSettings_App s_App;

	ref DayZScriptedSettings_Logger m_Logger;
	ref DayZScriptedSettings_Settings m_Settings;

	void DayZScriptedSettings_App()
	{
		s_App = this;

		m_Settings = new DayZScriptedSettings_Settings(m_Name);
		m_Logger = new DayZScriptedSettings_Logger(m_Name);
	}

	static DayZScriptedSettings_App GetInstance()
	{
		if (!s_App) new DayZScriptedSettings_App();
		return s_App;
	}
}
