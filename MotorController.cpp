#include "MotorController.h"

using namespace Phantom;

MotorController::MotorController(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB): pinPWM(pinPWM), pinDirA(pinDirA), pinDirB(pinDirB) {
	pinMode(this->pinPWM, OUTPUT);
	pinMode(this->pinDirA, OUTPUT);
	pinMode(this->pinDirB, OUTPUT);
}

MotorController::MotorController(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB, uint8_t pinEnable): pinPWM(pinPWM), pinDirA(pinDirA), pinDirB(pinDirB), pinEnable(pinEnable) {
	pinMode(this->pinPWM, OUTPUT);
	pinMode(this->pinDirA, OUTPUT);
	pinMode(this->pinDirB, OUTPUT);

	this->enablePin = true;
}

void MotorController::setValue(float value) {
	this->value = value;
}

float MotorController::getValue() {
	return this->value;
}

void MotorController::enable() {
	enabled = true;
	if (enablePin) { // Check if motor controller has an enable pin
		digitalWrite(pinEnable, HIGH);
	}
	else {
		digitalWrite(pinPWM, HIGH);
	}
}

void MotorController::disable() {
	enabled = false;
	if (enablePin) { // Check if motor controller has an enable pin
		digitalWrite(pinEnable, LOW);
	}
	else {
		digitalWrite(pinPWM, LOW);
	}
}

void MotorController::update() {
	if (enabled) {
		digitalWrite(pinDirA, value > 0.0f); // Use sign to set direction pins 
		digitalWrite(pinDirA, value < 0.0f);
		analogWrite(pinPWM, Utils::mapVal(value, -1.0f, 1.0f, 0.0f, 255.0f)); // Write PWM Value
	}
}