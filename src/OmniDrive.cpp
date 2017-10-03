#include "OmniDrive.h"

using namespace Phantom;

OmniDrive::OmniDrive(MotorBase& motorA, MotorBase& motorB, MotorBase& motorC, MotorBase& motorD):
	motorA(motorA),
	motorB(motorB),
	motorC(motorC),
	motorD(motorD) {

}

void OmniDrive::set(float direction, float magnitude, float rotation) {
	direction *= PI/180;
	float xMagnitude = sin(direction); //x component of the angle
	float yMagnitude = cos(direction); //y component of the angle

	float motorSpeedA = -xMagnitude + yMagnitude + rotation; //motor a
	float motorSpeedB =  xMagnitude + yMagnitude + rotation; //motor b
	float motorSpeedC = -xMagnitude + yMagnitude - rotation; //motor c
	float motorSpeedD =  xMagnitude + yMagnitude - rotation; //motor d

	motorA.set(magnitude*motorSpeedA);
	motorB.set(magnitude*motorSpeedB);
	motorC.set(magnitude*motorSpeedC);
	motorD.set(magnitude*motorSpeedD);
}