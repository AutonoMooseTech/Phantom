#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "Phantom.h"
#include "Pulse.h"

namespace Phantom {
	class Ultrasonic {
	private:
		uint8_t trigPin;
		uint8_t echoPin;
		uint16_t trigPulseDelta = 10; // In Microseconds

		uint16_t distance;

		float aquire();
	public:
		Ultrasonic(uint8_t trigPin, uint8_t echoPin);

		float get();
	};
}

#endif