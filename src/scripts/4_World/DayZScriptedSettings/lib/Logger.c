class DayZScriptedSettings_Logger
{
    string m_AppName;
    string m_LogFile;

    void DayZScriptedSettings_Logger(string AppName)
    {
        m_LogFile = "$profile:" + AppName + ".log";
        m_AppName = AppName;
    }

    void Log(string message, DayZScriptedSettings_LogLevel DebugLogLevel = DayZScriptedSettings_LogLevel.DEBUG)
    {
		if(!DayZScriptedSettings_App || !DayZScriptedSettings_App.GetInstance() || !DayZScriptedSettings_App.GetInstance().m_Settings) return;
		DayZScriptedSettings_Settings settings = DayZScriptedSettings_App.GetInstance().m_Settings;

        if(settings.debug_log_level < DebugLogLevel) return;
		if(GetGame().IsClient()) return;

		string timestamp = DayZScriptedSettings_Helper.GetTimestamp();
		message = "[" + timestamp + "] " + message.Trim();

		LogToFile(message);
    }

	private void LogToFile(string message)
	{
		FileHandle file = OpenFile(m_LogFile, FileMode.APPEND);

        if (file)
        {
            FPrintln(file, message);
            CloseFile(file);
        }
        else
        {
            Print("[" + m_AppName + "] Could not create logfile " + m_LogFile);
        }
	}
}
