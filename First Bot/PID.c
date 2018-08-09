#include "Vars.c"
#include "MotorSetUpVoids.c"
//#region Lift PID
//----------------------LIFT PID----------------------//

static float  liftR_Kp = 0.15; 	//Power Tuning Value
static float  liftRRequestedValue;
static float  liftR_Kd = 0.4;			// Requested Guess Value

float liftRD;
float liftRP;
float lastliftRError;
int waitLiftRerror = 150;
float liftRDF;

task liftRController()
{ // PID to set the lift/lock the lift during aton to increase accuracy
	float  liftRSensorCurrentValue;
	float  liftRError;
	float  liftRDrive;

	while( true )
	{
		// Read the sensor value and scale
		liftRSensorCurrentValue = SensorValue[ liftPot ];

		// calculate error
		liftRError =  liftRRequestedValue - liftRSensorCurrentValue;

		// calculate drive
		liftRP = (liftR_Kp * liftRError);

		liftRD = liftRError- lastliftRError;
		liftRDF = (liftR_Kd * liftRD);

		liftRDrive = liftRP + liftRDF;

		// limit drive
		if( liftRDrive > 127 )
			liftRDrive = 127;
		if( liftRDrive < (-127) )
			liftRDrive = (-127);

		// send to motor
		setLiftPower(liftRDrive);
		lastliftRError = liftRError;
		// Don't hog cpu
		wait1Msec( 25 );
	}
}
//#endregion
//#region Mobile PID
//----------------------Mobile Bar PID----------------------//
/*
static float  mobileR_Kp = 0.30; //Power Tuning Value
static float  mobileRRequestedValue;
static float  mobileR_Kd = 0.5; // Requested Guess Value

float mobileRD;						//Establishing variables
float mobileRP;
float lastmobileRError;
float mobileRDF;
int waitMobliERerror = 100;
float  mobileRSensorCurrentValue;

task mobileRController()
{// PID to set the mobile goal/lock the mobile goal during aton to increase accuracy
	float  mobileRSensorCurrentValue;
	float  mobileRError;
	float  mobileRDrive;

	while( true )
	{
		// Read the sensor value and scale
		mobileRSensorCurrentValue = SensorValue[ mobileP ];
		// calculate error
		mobileRError =  mobileRRequestedValue - mobileRSensorCurrentValue;

		// calculate drive
		mobileRP = (mobileR_Kp * mobileRError);

		mobileRD = mobileRError- lastmobileRError;
		mobileRDF = (mobileR_Kd * mobileRD);

		mobileRDrive = mobileRP + mobileRDF;

		// limit drive
		if( mobileRDrive > 127 )
			mobileRDrive = 127;
		if( mobileRDrive < (-127) )
			mobileRDrive = (-127);

		// send to motor
		setMobilePower(mobileRDrive);
		lastmobileRError = mobileRError;

		// Don't hog cpu
		wait1Msec( 25 );
	}
}*/
//#endregion
