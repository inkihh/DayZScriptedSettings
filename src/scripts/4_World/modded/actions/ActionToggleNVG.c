modded class ActionToggleNVG
{
    override bool CanBeUsedInVehicle()
    {
		if(!DayZScriptedSettings_App.GetInstance().m_Settings.can_toggle_nvg_in_vehicle || DayZScriptedSettings_App.GetInstance().m_Settings.can_toggle_nvg_in_vehicle == 0)
			return super.CanBeUsedInVehicle();
		
        return true;
    }
}
