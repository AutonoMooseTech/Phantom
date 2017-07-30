#include "MotorController.h"

MotorController::MotorController(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB): pinPWM(pinPWM), pinDirA(pinDirA), pinDirB(pinDirB) {
	pinMode(this->pinPWM, OUTPUT);
	pinMode(this->pinDirA, OUTPUT);
	pinMode(this->pinDirB, OUTPUT);
}

void MotorController::set(float value) {
	this->value = value;
}

float MotorController::get() {
	return this->value;
}

void MotorController::update() {
	digitalWrite(this->pinDirA, this->value > 0.0f); // Use sign to set direction pins 
	digitalWrite(this->pinDirA, this->value < 0.0f);
	analogWrite(this->pinPWM, Utils::mapVal(this->value, -1.0f, 1.0f, 0, 255)); // Write PWM Value
}

