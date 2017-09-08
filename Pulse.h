#ifndef PULSE_H
#define PULSE_H

#include "Phantom.h"
#include "DigitalOutput.h"

namespace Phantom {
	// Pulse and output HIGH and then return to LOW after given delay (in milliseconds)
	// Note this function is blocking
	inline void pulseHigh(byte pin, uint32_t deltaUs = 0) {
		auto output = new DigitalOutput(pin);
		output->set(HIGH);
		if(deltaUs) delay(deltaUs);
		output->set(LOW);
		delete output;
	}

	// Pulse and output HIGH and then return to LOW after given delay (in microseconds)
	// Note this function is blocking
	inline void pulseHighMicro(byte pin, uint32_t deltaUs = 0) {
		auto output = new DigitalOutput(pin);
		output->set(HIGH);
		if(deltaUs) delayMicroseconds(deltaUs);
		output->set(LOW);
		delete output;
	}

	// Pulse an output LOW and then return to HIGH after given delay (in milliseconds)
	// Note this function is blocking
	inline void pulseLow(byte pin, uint32_t deltaUs = 0) {
		auto output = new DigitalOutput(pin);
		output->set(LOW);
		if(deltaUs) delay(deltaUs);
		output->set(HIGH);
		delete output;
	}

	// Pulse an output LOW and then return to HIGH after given delay (in microseconds)
	// Note this function is blocking
	inline void pulseLowMicro(byte pin, uint32_t deltaUs = 0) {
		auto output = new DigitalOutput(pin);
		output->set(LOW);
		if(deltaUs) delayMicroseconds(deltaUs);
		output->set(HIGH);
		delete output;
	}
}

#endif