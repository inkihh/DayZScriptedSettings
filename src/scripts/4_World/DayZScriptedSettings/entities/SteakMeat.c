modded class BearSteakMeat
{
	override void HandleFoodStageChangeAgents(FoodStageType stageOld, FoodStageType stageNew)
	{
		int mask1 = eAgents.SALMONELLA|eAgents.BRAIN|eAgents.HEAVYMETAL;
		int mask2 = eAgents.SALMONELLA|eAgents.HEAVYMETAL;

		if(!DayZScriptedSettings_App.GetInstance().m_Settings.remove_predator_meat_poisoning || DayZScriptedSettings_App.GetInstance().m_Settings.remove_predator_meat_poisoning == 0)
		{
			DayZScriptedSettings_App.GetInstance().m_Logger.Log("[BearSteakMeat.HandleFoodStageChangeAgents] remove_predator_meat_poisoning nonexistant or 0, using vanilla behavior");
		}
		else
		{
			DayZScriptedSettings_App.GetInstance().m_Logger.Log("[BearSteakMeat.HandleFoodStageChangeAgents] remove_predator_meat_poisoning!=0, using custom behavior");
			mask1 = eAgents.SALMONELLA|eAgents.BRAIN;
			mask2 = eAgents.SALMONELLA;
		}

		switch (stageNew)
		{
			case FoodStageType.BAKED:
			case FoodStageType.BOILED:
			case FoodStageType.DRIED:
				RemoveAllAgentsExcept(mask1);
			break;
			
			case FoodStageType.BURNED:
				RemoveAllAgentsExcept(mask2);
			break;
		}
	}
}

modded class WolfSteakMeat
{
	override void HandleFoodStageChangeAgents(FoodStageType stageOld, FoodStageType stageNew)
	{
		int mask1 = eAgents.SALMONELLA|eAgents.BRAIN|eAgents.HEAVYMETAL;
		int mask2 = eAgents.SALMONELLA|eAgents.HEAVYMETAL;

		if(!DayZScriptedSettings_App.GetInstance().m_Settings.remove_predator_meat_poisoning || DayZScriptedSettings_App.GetInstance().m_Settings.remove_predator_meat_poisoning == 0)
		{
			DayZScriptedSettings_App.GetInstance().m_Logger.Log("[WolfSteakMeat.HandleFoodStageChangeAgents] remove_predator_meat_poisoning nonexistant or 0, using vanilla behavior");
		}
		else
		{
			DayZScriptedSettings_App.GetInstance().m_Logger.Log("[WolfSteakMeat.HandleFoodStageChangeAgents] remove_predator_meat_poisoning!=0, using custom behavior");
			mask1 = eAgents.SALMONELLA|eAgents.BRAIN;
			mask2 = eAgents.SALMONELLA;
		}

		switch (stageNew)
		{
			case FoodStageType.BAKED:
			case FoodStageType.BOILED:
			case FoodStageType.DRIED:
				RemoveAllAgentsExcept(eAgents.SALMONELLA|eAgents.BRAIN);
			break;
			
			case FoodStageType.BURNED:
				RemoveAllAgentsExcept(eAgents.SALMONELLA);
			break;
		}
	}
}
