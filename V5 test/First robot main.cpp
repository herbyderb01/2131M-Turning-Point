#include "robot-config.h"

//Creates a competition object that allows access to Competition methods.
vex::competition    Competition;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {

	while(1) 
	{
        
        LeftMotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
        RightMotor.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
        
        //Lift Control
        if(Controller1.ButtonUp.pressing()) { //If button up is pressed...
            //...Spin the arm motor forward.
            LiftMotor.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
        }   
        else(Controller1.ButtonDown.pressing()) {//If the down button is pressed...
            ..Spin the arm motor backward.
            LiftMotor.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
        }   
        else//If the the up or down button is not pressed...
            ...Stop the arm motor.
            LiftMotor.stop(vex::brakeType::brake);
        }
        
        //Wrist Control
        if(Controller1.ButtonA.pressing()) { //If the A button is pressed...
            //...Spin the claw motor forward.
            WristMotor.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
        }
        else if(Controller1.ButtonY.pressing()) { //If the Y button is pressed...
            //...Spin the claw motor backward.
            WristMotor.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
        }
        else { //If the A or Y button are not pressed...
            //...Stop the claw motor. 
            WristMotor.stop(vex::brakeType::brake);       
        }
		vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
    }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}