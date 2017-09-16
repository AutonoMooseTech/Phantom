#include "SenseLight.h"

using namespace Phantom;

SenseLight::SenseLight(uint8_t pinAnalogIn): pinAnalogIn(pinAnalogIn) {
	pinMode(pinAnalogIn, INPUT);
}

float SenseLight::get() {
	return map(analogRead(pinAnalogIn), 0, 1023, 0.0f, 1.0f);
}