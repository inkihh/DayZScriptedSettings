modded class BearSteakMeat extends Edible_Base
{
	override void HandleFoodStageChangeAgents(FoodStageType stageOld, FoodStageType stageNew)
	{
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

modded class WolfSteakMeat extends Edible_Base
{
	override void HandleFoodStageChangeAgents(FoodStageType stageOld, FoodStageType stageNew)
	{
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
