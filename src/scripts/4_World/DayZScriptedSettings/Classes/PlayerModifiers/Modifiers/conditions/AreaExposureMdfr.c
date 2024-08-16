modded class AreaExposureMdfr {
	override void BleedingSourceCreateCheck(PlayerBase player) {
		if(DayZScriptedSettings_App.GetInstance().m_Settings.EnableGasMaskOnlyContaminatedAreas) {
			return;
		} else {
			super.BleedingSourceCreateCheck(player);
		}
	}
}