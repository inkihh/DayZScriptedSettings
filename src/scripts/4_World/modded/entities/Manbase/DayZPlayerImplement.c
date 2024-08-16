modded class DayZPlayerImplement extends DayZPlayer
{
    override void OnSprintStart()
	{
        if( DayZScriptedSettings_App.GetInstance().m_Settings.EnableLeaningWhileSprinting)
            return;

		super.OnSprintStart();
    }

    override void OnSprintEnd()
	{
        if( DayZScriptedSettings_App.GetInstance().m_Settings.EnableLeaningWhileSprinting) {
            return;
    
		super.OnSprintEnd();
    }
}