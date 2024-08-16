modded class ActionToggleNVG
{
    override bool CanBeUsedInVehicle()
    {
		if(DayZScriptedSettings_App.GetInstance().m_Settings.VehicleCE_CanToggleNvgInVehicle)
        	return true;
			
		return super.CanBeUsedInVehicle();
    }
}
