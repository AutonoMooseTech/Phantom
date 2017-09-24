#include "NXTLightSensor.h"

using namespace Phantom;

NXTLightSensor::NXTLightSensor(uint8_t pinInput): pinInput(pinInput) {
	pinMode(pinInput, INPUT);
}

NXTLightSensor::NXTLightSensor(uint8_t pinInput, uint8_t pinLed): pinInput(pinInput), pinLed(pinLed) {
	pinMode(pinInput, INPUT);
	pinMode(pinLed, OUTPUT);
}

float NXTLightSensor::get() {
	return map(analogRead(pinInput), 1023, 0, 0.0f, 1.0f); // Invert and map input to output
}

void NXTLightSensor::led(bool state) {
	digitalWrite(pinInput, state);
}