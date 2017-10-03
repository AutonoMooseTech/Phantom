#include "DigitalOutput.h"

using namespace Phantom;

DigitalOutput::DigitalOutput(uint8_t pin): pin(pin) {
	pinMode(pin, OUTPUT);
}

void DigitalOutput::set(bool state) {
	digitalWrite(pin, state);
}