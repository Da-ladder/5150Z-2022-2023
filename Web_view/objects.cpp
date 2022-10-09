#include "vex.h"
 
using namespace vex;

struct chassis_Set {
 
 void reset() {
   leftMotorA.resetRotation();
   leftMotorB.resetRotation();
   rightMotorA.resetRotation();
   rightMotorB.resetRotation();
 }
 
 // CREATES A METHOD TO APPLY POWER TO CHASSIS
 void move(double rPower, double lPower) {
   leftMotorA.spin(fwd, rPower, voltageUnits::volt);
   leftMotorB.spin(fwd, rPower, voltageUnits::volt);
   rightMotorA.spin(fwd, rPower, voltageUnits::volt);
   rightMotorB.spin(fwd, lPower, voltageUnits::volt);
 }
 
 // CREATES A METHOD TO BRAKE THE CHASSIS MOTORS
 void brake() {
   leftMotorA.setBrake(hold);
   leftMotorB.setBrake(hold);
   rightMotorA.setBrake(hold);
   rightMotorB.setBrake(hold);
 }
 
 // CREATES A METHOD TO BOTH APPLY ZERO VOLTAGE AND BRAKE MOTORS
 void rest() {
   move(0, 0);
   brake();
 }
 
 void driveFor(double distance, double percent = 100) {
 
   // ALLOWS FOR CHASSIS CONTROL
 
   chassis.setDriveVelocity(percent, pct);
 
   chassis.driveFor(fwd, distance, inches);
 }
 
 void turnFor(double degs) {
 
   // ALLOWS FOR CONTROL OF LIFT
 
   chassis.setTurnVelocity(5, pct);
 
   chassis.turnFor(degs, deg);
 }
};
