vex::brain Brain;

vex::motor LeftFMotor = vex::motor(vex::PORT1);
vex::motor RightFMotor = vex::motor(vex::PORT3, true);
vex::motor LeftBMotor = vex::motor(vex::PORT2);
vex::motor RightBMotor = vex::motor(vex::PORT4, true);

vex::motor LiftMotor = vex::motor(vex::PORT5);
vex::motor WristMotor = vex::motor(vex::PORT6);
vex::motor IntakeMotor = vex::motor(vex::PORT7);
vex::motor PuncherMotor = vex::motor(vex::PORT8);

vex::controller Controller1 = vex::controller();