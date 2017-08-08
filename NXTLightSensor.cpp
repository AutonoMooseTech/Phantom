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
	return lightValue;
}

void NXTLightSensor::led(bool state) {
	ledState = state;
}

void NXTLightSensor::update() {
	if (ledState != ledStateLast) digitalWrite(pinLed, ledState); // If state changed, write state
	ledStateLast = ledState; // Remember last state

	lightValue = map(analogRead(pinInput), 1023, 0, 0.0f, 1.0f); // Invert and map input to output
}