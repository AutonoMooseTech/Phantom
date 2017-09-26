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

		uint16_t timeout = 23200; // in uS, default is maximum (4 meters)
	};
}

#endif