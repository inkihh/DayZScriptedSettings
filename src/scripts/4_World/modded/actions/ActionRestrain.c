modded class ActionRestrainSelf
{
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
		if(DayZScriptedSettings_App.GetInstance().m_Settings.DisablePlayerRestraining)
			return false;

		return super.ActionCondition(player, target, item);
	}
}

modded class ActionRestrainTarget
{
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
		if(DayZScriptedSettings_App.GetInstance().m_Settings.DisablePlayerRestraining)
	        return false;
	
		return super.ActionCondition(player, target, item);
    }
}
