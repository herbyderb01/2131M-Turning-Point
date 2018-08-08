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
	setPunchPower(127);
	wait1Msec(1000);
	setPunchPower(0);
}


task turnWrist()
{
		if(buttontoggle == 0){
		setWristPower(127);
		wait1Msec(250);
		setWristPower(0);
		}
		if(buttontoggle == 1){
		setWristPower(-127);
		wait1Msec(250);
		setWristPower(0);
		}
}
