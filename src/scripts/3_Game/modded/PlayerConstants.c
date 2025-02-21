modded class PlayerConstants
{
	//
	// show damage, feet bleeding
	//
	static const float BAREFOOT_MOVEMENT_BLEED_MODIFIER = 0.1; 		// 0.1
	static const float SHOES_MOVEMENT_DAMAGE_PER_STEP 	= 0.020; 	// 0.035

	//
	// food/water health loss
	//
	static const float LOW_ENERGY_DAMAGE_PER_SEC	= 0.09;	// 0.05
	static const float LOW_WATER_DAMAGE_PER_SEC		= 0.15;	// 0.05
	
	static const float METABOLIC_SPEED_ENERGY_WALK		= 0.08; // 0.1
	static const float METABOLIC_SPEED_ENERGY_JOG		= 0.15;	// 0.3
	static const float METABOLIC_SPEED_ENERGY_SPRINT	= 0.4;	// 0.6

	//
	// shock numbers
	//
	static const float SHOCK_REFILL_CONSCIOUS_SPEED		= 5;	// 5
	static const float SHOCK_REFILl_UNCONSCIOUS_SPEED	= 0.5;	// 1

	//
	// blood loss and such
	//
	static const float BLEEDING_SOURCE_BLOODLOSS_PER_SEC 	= -12; 		// -20
	static const float BLEEDING_SOURCE_FLOW_MODIFIER_MEDIUM = 0.4; 		// 0.6
	static const float BLEEDING_SOURCE_FLOW_MODIFIER_LOW	= 0.1; 		// 0.1
	static const int BLEEDING_SOURCE_DURATION_NORMAL 		= 300; 		// 300
	static const float BLEEDING_LOW_PRESSURE_BLOOD 			= 4000.0;	// 4000.0
	static const float BLEEDING_LOW_PRESSURE_MIN_MOD 		= 0.3; 		// 0.3

	static const float BAREFOOT_MOVEMENT_BLEED_MODIFIER = 0;	// 0.1
	static const float SHOES_MOVEMENT_DAMAGE_PER_STEP = 0; 		// 0.035

	static const float CHANCE_TO_BLEED_SLIDING_LADDER_PER_SEC = 0; 	// 0.3
	static const float GLOVES_DAMAGE_SLIDING_LADDER_PER_SEC = 0; 	// -3

	//
	// Broken legs
	//
	static const float 	LEG_HEALTH_REGEN_BROKEN = 0.36; // 0.18

}
