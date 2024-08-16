modded class BearSteakMeat
{
	override void HandleFoodStageChangeAgents(FoodStageType stageOld, FoodStageType stageNew)
	{
		int mask1 = eAgents.SALMONELLA|eAgents.BRAIN|eAgents.HEAVYMETAL;
		int mask2 = eAgents.SALMONELLA|eAgents.HEAVYMETAL;

		if(!DayZScriptedSettings_App.GetInstance().m_Settings.RemovePredatorMeatPoisoning || DayZScriptedSettings_App.GetInstance().m_Settings.RemovePredatorMeatPoisoning == 0)
		{
			DayZScriptedSettings_App.GetInstance().m_Logger.Log("[BearSteakMeat.HandleFoodStageChangeAgents] RemovePredatorMeatPoisoning nonexistant or 0, using vanilla behavior");
		}
		else
		{
			DayZScriptedSettings_App.GetInstance().m_Logger.Log("[BearSteakMeat.HandleFoodStageChangeAgents] RemovePredatorMeatPoisoning!=0, using custom behavior");
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

		if(!DayZScriptedSettings_App.GetInstance().m_Settings.RemovePredatorMeatPoisoning || DayZScriptedSettings_App.GetInstance().m_Settings.RemovePredatorMeatPoisoning == 0)
		{
			DayZScriptedSettings_App.GetInstance().m_Logger.Log("[WolfSteakMeat.HandleFoodStageChangeAgents] RemovePredatorMeatPoisoning nonexistant or 0, using vanilla behavior");
		}
		else
		{
			DayZScriptedSettings_App.GetInstance().m_Logger.Log("[WolfSteakMeat.HandleFoodStageChangeAgents] RemovePredatorMeatPoisoning!=0, using custom behavior");
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
