modded class MissionGameplay {
    DayZScriptedSettings_App m_DayZScriptedSettings_App;
    
    override void OnMissionStart() {
        super.OnMissionStart();
        if(!m_DayZScriptedSettings_App) m_DayZScriptedSettings_App = DayZScriptedSettings_App.GetInstance();
        Print("[DayZScriptedSettings] DayZScriptedSettings Client");
    }
}    