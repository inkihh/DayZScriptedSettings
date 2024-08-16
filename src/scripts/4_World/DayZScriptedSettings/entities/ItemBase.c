modded class ItemBase {
	override bool DamageItemInCargo(float damage) {
		if(DayZScriptedSettings_App.GetInstance().m_Settings.DisableItemsInCargoDamage) {
			return false;
		} else {
			return super.DamageItemInCargo(damage);
		}
	}
	override bool DamageItemAttachments(float damage) {
		if(DayZScriptedSettings_App.GetInstance().m_Settings.DisableAttachmentItemsDamage) {
			return false;
		} else {
			return super.DamageItemAttachments(damage);
		}
	}
}