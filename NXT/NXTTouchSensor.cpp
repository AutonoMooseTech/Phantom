#include "NXTTouchSensor.h"

using namespace Phantom;

NXTTouchSensor::NXTTouchSensor(uint8_t pinInput): Base(), Scheduler(), pinInput(pinInput) {
	pinMode(pinInput, INPUT_PULLUP);
	add(this, 0);
}

void NXTTouchSensor::get() {
	return state;
}

void NXTTouchSensor::update() {
	state = digitalRead(pinInput);
	add(this, 0);
}