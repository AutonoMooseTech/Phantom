#include "DigitalInput.h"

using namespace Phantom;

DigitalInput::DigitalInput(uint8_t pin): pin(pin) {
	pinMode(pin, INPUT);
}

DigitalInput::DigitalInput(uint8_t pin, bool inputPullup): pin(pin) {
	if (inputPullup) {
		pinMode(pin, INPUT_PULLUP);
	}
	else {
		pinMode(pin, INPUT);
	}
}

bool DigitalInput::get() {
	return digitalRead(pin);
}