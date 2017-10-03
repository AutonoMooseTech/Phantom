#include "NXTTouchSensor.h"

using namespace Phantom;

NXTTouchSensor::NXTTouchSensor(uint8_t pinInput): pinInput(pinInput) {
	pinMode(pinInput, INPUT_PULLUP);
}

float NXTTouchSensor::get() {
	return state;
}

void NXTTouchSensor::update() {
	state = digitalRead(pinInput);
}