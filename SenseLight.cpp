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
	value = Utils::mapVal(float(analogRead(pinAnalogIn)), 0.0f, 255.0f, -1.0f, 1.0f);
}