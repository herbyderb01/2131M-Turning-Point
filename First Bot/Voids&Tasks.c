#include "Vars.c"
#include "MotorSetUpVoids.c"
task driveCaps()
{
	while(true)
	{
		setDrivePower(vexRT[Ch3],vexRT[Ch2]);
	}
}

task driveBall()
{
	while(true)
	{
   	setDrivePower(-(vexRT[Ch2]),-(vexRT[Ch3]));
	}
}

task ReadyAimFIRE()
{

}
