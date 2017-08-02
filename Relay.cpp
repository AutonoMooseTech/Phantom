#include "Relay.h"

using namespace Phantom;

Relay::Relay(uint8_t pin, type_t type): pin(pin), type(type) {
	pinMode(pin, OUTPUT);
}

void Relay::on() {
	state = !bool(type);
}

void Relay::off() {
	state = bool(type);
}

void Relay::update() {
	digitalWrite(pin, state);
}