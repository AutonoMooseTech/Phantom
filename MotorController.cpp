#include "MotorController.h"

using namespace Phantom;

MotorController::MotorController(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB): pinPWM(pinPWM), pinDirA(pinDirA), pinDirB(pinDirB) {
	pinMode(this->pinPWM, OUTPUT);
	pinMode(this->pinDirA, OUTPUT);
	pinMode(this->pinDirB, OUTPUT);
}

void MotorController::set(float value) {
	this->value = value;
	enabled = true;
}

void MotorController::disable() {
	enabled = false;
	update();
}

void MotorController::update() {
	if (enabled) {
		digitalWrite(pinDirA, value > 0.0f); // Use sign to set direction pins 
		digitalWrite(pinDirA, value < 0.0f);
		analogWrite(pinPWM, map(fabs(value), 0.0f, 1.0f, this->min, this->max)); // Write PWM Value
	}
	else {
		digitalWrite(pinDirA, LOW); // Use sign to set direction pins 
		digitalWrite(pinDirA, LOW);
		digitalWrite(pinPWM, LOW);
	}
}