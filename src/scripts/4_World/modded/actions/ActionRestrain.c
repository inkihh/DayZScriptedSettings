modded class ActionRestrainSelf
{
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
		if(!DayZScriptedSettings_App.GetInstance().m_Settings.disable_player_restraining || DayZScriptedSettings_App.GetInstance().m_Settings.disable_player_restraining == 0)
			return super.ActionCondition(player, target, item);

		return false;
    }
}

modded class ActionRestrainTarget
{
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
		if(!DayZScriptedSettings_App.GetInstance().m_Settings.disable_player_restraining || DayZScriptedSettings_App.GetInstance().m_Settings.disable_player_restraining == 0)
			return super.ActionCondition(player, target, item);

        return false;
    }
}
