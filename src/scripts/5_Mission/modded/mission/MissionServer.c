modded class MissionServer
{
    DayZScriptedSettings_App m_DayZScriptedSettings_App;

    override void OnInit()
    {
        super.OnInit();

        if(!m_DayZScriptedSettings_App) m_DayZScriptedSettings_App = DayZScriptedSettings_App.GetInstance();
		
        Print("[DayZScriptedSettings] DayZScriptedSettings startup");
        Print("[DayZScriptedSettings] If you're happy, please donate to https://ko-fi.com/inkihh <3");
    }
}
