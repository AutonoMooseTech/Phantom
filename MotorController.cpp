#include "MotorController.h"

using namespace Phantom;

MotorController::MotorController(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB): pinPWM(pinPWM), pinDirA(pinDirA), pinDirB(pinDirB) {
	pinMode(this->pinPWM, OUTPUT);
	pinMode(this->pinDirA, OUTPUT);
	pinMode(this->pinDirB, OUTPUT);
}

void MotorController::set(float value) {
	digitalWrite(this->pinDirA, value > 0.0f); // Use sign to set direction pins 
	digitalWrite(this->pinDirB, value < 0.0f);
	analogWrite(this->pinPWM, map(float(fabs(value)), 0.0f, 1.0f, min, max)); // Write PWM Value
}

void MotorController::setMin(uint8_t min) {
	this->min = min;
}

void MotorController::setMax(uint8_t max) {
	this->max = max;
}

void MotorController::setBounds(uint8_t min, uint8_t max) {
	setMin(min);
	setMax(max);
}

void MotorController::disable() {
	digitalWrite(this->pinDirA, LOW); // Use sign to set direction pins 
	digitalWrite(this->pinDirB, LOW);
	digitalWrite(this->pinPWM, LOW);
}