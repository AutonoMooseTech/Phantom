#include "SenseLight.h"

using namespace Phantom;

SenseLight::SenseLight(uint8_t pinAnalogIn): pinAnalogIn(pinAnalogIn) {
	pinMode(pinAnalogIn, INPUT);
}

float SenseLight::get() {
	return map(analogRead(pinAnalogIn), uint32_t(0), uint32_t(1023), -1.0f, 1.0f);
}