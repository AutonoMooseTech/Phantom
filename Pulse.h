#ifndef PULSE_H
#define PULSE_H

#include "Phantom.h"

namespace Phantom {
	// Pulse and output HIGH and then return to LOW after given delay (in milliseconds)
	// Note this function is blocking
	inline void pulseHigh(byte pin, uint32_t deltaUs = 0) {
		digitalWrite(pin, HIGH);
		if(deltaUs) delay(deltaUs);
		digitalWrite(pin, LOW);
	}

	// Pulse and output HIGH and then return to LOW after given delay (in microseconds)
	// Note this function is blocking
	inline void pulseHighMicro(byte pin, uint32_t deltaUs = 0) {
		digitalWrite(pin, HIGH);
		if(deltaUs) delayMicroseconds(deltaUs);
		digitalWrite(pin, LOW);
	}

	// Pulse an output LOW and then return to HIGH after given delay (in milliseconds)
	// Note this function is blocking
	inline void pulseLow(byte pin, uint32_t deltaUs = 0) {
		digitalWrite(pin, LOW);
		if(deltaUs) delay(deltaUs);
		digitalWrite(pin, HIGH);
	}

	// Pulse an output LOW and then return to HIGH after given delay (in microseconds)
	// Note this function is blocking
	inline void pulseLowMicro(byte pin, uint32_t deltaUs = 0) {
		digitalWrite(pin, LOW);
		if(deltaUs) delayMicroseconds(deltaUs);
		digitalWrite(pin, HIGH);
	}
}

#endif