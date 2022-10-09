using namespace vex;

extern brain Brain;

// VEXcode devices
extern drivetrain chassis;
extern controller Controller1;

extern motor_group leftDrive;
extern motor_group rightDrive;

extern motor leftMotorA;
extern motor leftMotorB;
extern motor rightMotorA;
extern motor rightMotorB;

extern void chassisControlTank();
extern void chassisControlArcade();


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
