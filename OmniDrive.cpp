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
}

void OmniDrive::update() {
	xMagnitude = sin(this->direction*(PI/180)); //x component of the angle
	yMagnitude = cos(this->direction*(PI/180)); //y component of the angle

	motorSpeedA = -xMagnitude + yMagnitude + rotation; //motor a
	motorSpeedB =  xMagnitude + yMagnitude - rotation; //motor b
	motorSpeedC = -xMagnitude + yMagnitude - rotation; //motor c
	motorSpeedD =  xMagnitude + yMagnitude + rotation; //motor d

	maxPower /= max(motorSpeedA, max(motorSpeedB, max(motorSpeedC, motorSpeedD)));

	motorA.set(maxPower*motorSpeedA);
	motorA.set(maxPower*motorSpeedB);
	motorA.set(maxPower*motorSpeedC);
	motorA.set(maxPower*motorSpeedD);
}