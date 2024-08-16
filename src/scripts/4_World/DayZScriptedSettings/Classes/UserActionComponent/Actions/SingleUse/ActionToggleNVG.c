modded class ActionToggleNVG: ActionBase {
	override bool CanBeUsedInVehicle() {
		if(DayZScriptedSettings_App.GetInstance().m_Settings.EnableNVGsInVehicle) {
			return true; 
		} else {
			return super.CanBeUsedInVehicle();
		}	
	}
}