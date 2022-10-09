#include "objects.cpp"
#include "vex.h"
 
using namespace vex;
 
// DEFINES A AREA WHERE CONTROLLER WILL NOT ACCEPT INPUT
int deadzone = 10;
 
// DEFINES A BOOLEAN TO HELP SWITCH CONTROLS
bool isArcade = true;
 
// DEININES A FUNCTION THAT CHANGES BOOL TO OPPOSITE TO
// CHANGE CONTROL SYTLES.
void controlSwitch() { isArcade = !isArcade; }
 
// FUNCTION THAT ALLOWS FOR A ARCADE STYLE OF DRIVE (SHARVA)
void chassisControlArcade() {
 if (isArcade == true) {
   int leftJoystickVal = 0, rightJoystickVal = 0;
 
   // ALLOWS FOR CONTROLS TO BE TUNED TO DRIVER'S PREFRENCE
   double sensitivity = 1;
   double turn = 0, power = 0;
   double lOutput = 0, rOutput = 0;
 
   // CREATES AN OBJECT
   chassis_Set controls;
 
   leftJoystickVal = Controller1.Axis4.value();
   rightJoystickVal = Controller1.Axis2.value();
 
   turn = (leftJoystickVal * sensitivity) / 10.58;
   power = (rightJoystickVal * sensitivity) / 10.58;
 
   lOutput = turn + power;
   rOutput = -turn + power;
 
   // APPLIES POWER TO THE MOTOR FROM OBJECT
   controls.move(rOutput, lOutput);
 
   // CHECKS IF THE CONTROLS ARE MOVING IF NOT
   // SET MOTORS TO BRAKE
   if (Controller1.Axis3.value() < deadzone ||
       Controller1.Axis4.value() < deadzone ||
       Controller1.Axis2.value() < deadzone) {
     controls.brake();
   }
 }
}
 
// FUNCTION THAT ALLOWS FOR A TANK STYLE OF DRIVE (ARTHUR)
void chassisControlTank() {
 if (isArcade == false) {
   int leftJoystickVal = 0, rightJoystickVal = 0;
   double sensitivity = 1;
   double lPower = 0, rPower = 0;
   double lOutput = 0, rOutput = 0;
 
   // INSTATIATES AN OBJECT
   chassis_Set controls;
 
   leftJoystickVal = Controller1.Axis3.value();
   rightJoystickVal = Controller1.Axis2.value();
 
   lPower = (leftJoystickVal * sensitivity) / 10.58;
   rPower = (rightJoystickVal * sensitivity) / 10.58;
 
   lOutput = lPower;
   rOutput = rPower;
 
   controls.move(rOutput, lOutput);
 
   if (Controller1.Axis3.value() < deadzone ||
       Controller1.Axis4.value() < deadzone ||
       Controller1.Axis2.value() < deadzone) {
     controls.brake();
   }
 }
}
