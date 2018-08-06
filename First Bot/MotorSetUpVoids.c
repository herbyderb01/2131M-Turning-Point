void setDrivePower(int left, int right)
{// Defining all of the motors for the -DRIVE-
	motor[LFrontD] = left;		//Define this motor as the left drive
	motor[RFrontD] = right;	//Define this motor as the right drive
	motor[LBackD] = left;		//Define this motor as the left drive
	motor[RBackD] = right;	//Define this motor as the right drive
}

void setLiftPower(int power)
{
	motor[RLift] = power;
	motor[LLift] = power;
}


void setRollerPower(int power)
{
	motor[Roller] = power;
}

void setWristPower(int power)
{
	motor[wrist] = power;
}

void setPunchPower(int power)
{
	motor[Puncher] = power;
}
