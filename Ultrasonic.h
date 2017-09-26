#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "Phantom.h"
#include "Pulse.h"

namespace Phantom {
	class Ultrasonic {
	public:
		Ultrasonic(uint8_t trigPin, uint8_t echoPin);

		float get();

		float setRange(float meters)
	private:
		uint8_t trigPin;
		uint8_t echoPin;

		timeout = 23200; // uS
	};
}

#endif