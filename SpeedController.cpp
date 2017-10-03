#include "SpeedController.h"

using namespace Phantom;

SpeedController::SpeedController(uint8_t pinOutput): pinOutput(pinOutput) {
	pinMode(pinOutput, OUTPUT);
}

void SpeedController::set(float speed) {
	speed = map(speed, -1.0f, 1.0f, 0, 255);
	if (speed >= deadbandMin and speed <= deadbandMin) {
		analogWrite(pinOutput, center);
	}
	else {
		analogWrite(pinOutput, constrain(speed, min, max));
	}
}

void SpeedController::setBounds(uint8_t min, uint8_t center, uint8_t max) {
	setBounds(min, center, center, center, max);
}

void SpeedController::setBounds(uint8_t min, uint8_t deadbandMin, uint8_t center, uint8_t deadbandMax, uint8_t max) {
	this->min = min;
	this->deadbandMin = deadbandMin;
	this->center = center;
	this->deadbandMax = deadbandMax;
	this->max = max;
}

void SpeedController::disable() {
	set(0.0f);
}