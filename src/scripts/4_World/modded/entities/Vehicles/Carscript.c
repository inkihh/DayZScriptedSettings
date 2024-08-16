modded class CarScript extends Car {
    override void EEOnCECreate()
	{
        float fuelMin = DayZScriptedSettings_App.GetInstance().m_Settings.VehicleCE_FuelMinSpawn;
        float fuelMax = DayZScriptedSettings_App.GetInstance().m_Settings.VehicleCE_FuelMaxSpawn;

        float coolantMin = DayZScriptedSettings_App.GetInstance().m_Settings.VehicleCE_CoolantMinSpawn;
        float coolantMax = DayZScriptedSettings_App.GetInstance().m_Settings.VehicleCE_CoolantMaxSpawn;

        float maxVolumeFuel = GetFluidCapacity( CarFluid.FUEL );
        float maxVolumeCoolant = GetFluidCapacity( CarFluid.COOLANT );

        float fuelFill = Math.RandomFloat( maxVolumeFuel * fuelMin, maxVolumeFuel * fuelMax );
        float coolantFill = Math.RandomFloat( maxVolumeCoolant * coolantMin, maxVolumeCoolant * coolantMax );

        Fill( CarFluid.FUEL, fuelFill );
        Fill( CarFluid.COOLANT, coolantFill );
    }
}