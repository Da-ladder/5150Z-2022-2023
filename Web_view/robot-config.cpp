#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// CONTROLLER DEFINTION
controller Controller1 = controller(primary);

// CHASSIS MOTOR DEFINITIONS
motor leftMotorA = motor(PORT12, ratio6_1, false);
motor leftMotorB = motor(PORT11, ratio6_1, false);
motor rightMotorA = motor(PORT20, ratio6_1, true);
motor rightMotorB = motor(PORT18, ratio6_1, true);

// MOTOR GROUPS
motor_group leftDrive(leftMotorA, leftMotorB);
motor_group rightDrive(rightMotorA, rightMotorB);

// DRIVE BASE
drivetrain chassis = drivetrain(leftDrive, rightDrive, 319.19, 295, 40, mm, 1);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // Nothing to initialize
}
