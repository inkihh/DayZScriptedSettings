modded class ActionToggleNVG
{
    override bool CanBeUsedInVehicle()
    {
		if(!DayZScriptedSettings_App.GetInstance().m_Settings.CanToggleNvgInVehicle || DayZScriptedSettings_App.GetInstance().m_Settings.CanToggleNvgInVehicle == 0)
			return super.CanBeUsedInVehicle();
		
        return true;
    }
}
