#include "SenseLight.h"

using namespace Phantom;

SenseLight::SenseLight(uint8_t pinAnalogIn): pinAnalogIn(pinAnalogIn) {
	pinMode(pinAnalogIn, INPUT);
}

SenseLight::SenseLight(uint8_t pinAnalogIn, uint8_t pinLightOut): pinAnalogIn(pinAnalogIn), pinLightOut(pinLightOut) {
	pinMode(pinAnalogIn, INPUT);
	pinMode(pinLightOut, OUTPUT);
}

float SenseLight::get() {
	return value;
}

void SenseLight::update() {
	value = map(analogRead(pinAnalogIn), uint32_t(0), uint32_t(1023), -1.0f, 1.0f);
}