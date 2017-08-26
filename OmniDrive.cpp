#include "OmniDrive.h"

using namespace Phantom;

OmniDrive::OmniDrive(MotorController& motorA, MotorController& motorB, MotorController& motorC, MotorController& motorD):
	motorA(motorA),
	motorB(motorB),
	motorC(motorC),
	motorD(motorD) {

}

void OmniDrive::set(float direction, float magnitude) {
	set(direction, magnitude, 0.0f);
}

void OmniDrive::set(float direction, float magnitude, float rotation) {
	this->direction = direction;
	this->magnitude = magnitude;
	this->rotation 	= rotation;

	maxPower = magnitude;
	xMagnitude = sin(direction*(PI/180)); //x component of the angle
	yMagnitude = cos(direction*(PI/180)); //y component of the angle

	motorSpeedA = -xMagnitude + yMagnitude + rotation; //motor a
	motorSpeedB =  xMagnitude + yMagnitude - rotation; //motor b
	motorSpeedC = -xMagnitude + yMagnitude - rotation; //motor c
	motorSpeedD =  xMagnitude + yMagnitude + rotation; //motor d

	maxPower /= std::max({motorSpeedA, motorSpeedB, motorSpeedC, motorSpeedD});

	motorA.set(maxPower*motorSpeedA);
	motorB.set(maxPower*motorSpeedB);
	motorC.set(maxPower*motorSpeedC);
	motorD.set(maxPower*motorSpeedD);

	motorA.update();
	motorB.update();
	motorC.update();
	motorD.update();
}