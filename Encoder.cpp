#include "Encoder.h"

using namespace Phantom;

// 0,  1, 2, 3, 4, 5, 6,  7,  8, 9, 10, 11, 12, 13, 14, 15
// 0, -1, 1, 0, 1, 0, 0, -1, -1, 0,  0,  1,  0,  1, -1,  0

Encoder::Encoder(uint8_t pinA, uint8_t pinB): pinA(pinA), pinB(pinB) {
	pinMode(pinA, INPUT);
	pinMode(pinB, INPUT);
}

Encoder::Encoder(uint8_t pinA, uint8_t pinB, type_t type): pinA(pinA), pinB(pinB), type(type) {
	pinMode(pinA, INPUT);
	pinMode(pinB, INPUT);
}

int32_t Encoder::get() {
	return value / type;
}

int8_t Encoder::getDirection() {
	return direction;
}

bool Encoder::getChanged() {
	bool hasChanged = changed;
	changed = false;
	return hasChanged;
}

void Encoder::reset() {
	value = 0;
	direction = direction_t::STOPPED;
}

void Encoder::update() {
	uint8_t state = digitalRead(pinA) | (digitalRead(pinB) << 1);
	if (state != lastState) {
		changed = true;
		switch (state | (lastState << 2)) {
			case 1: case 7: case 8:	case 14:
				value--;
				direction = direction_t::BACKWARDS;
				break;
			case 2:	case 4:	case 11: case 13:
				value++;
				direction = direction_t::BACKWARDS;
				break;
		}
		lastState = state;
	}
	else {
		changed = false;
	}
} 