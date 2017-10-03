#include "DigitalInput.h"

using namespace Phantom;

DigitalInput::DigitalInput(uint8_t pin): pin(pin), InputBase() {
	pinMode(pin, INPUT);
}

bool DigitalInput::get() {
	return digitalRead(pin);
}

void DigitalInput::setPullup(bool state) {
	if (state) pinMode(pin, INPUT_PULLUP);
	else pinMode(pin, INPUT);
}