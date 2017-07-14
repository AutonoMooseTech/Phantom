#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>
#include "Utils.h"

namespace Phantom {
	class Ultrasonic {
	private:
		uint8_t trigPin;
		uint8_t echoPin;
		uint16_t trigPulseDelta = 10; // In Milliseconds

		//uint16_t distance;

		// Timing
		//uint16_t lastTrig;

	public:
		Ultrasonic(uint8_t trigPin, uint8_t echoPin);

		uint16_t get(void); // returns last value aquired in mm

		//void refresh(); // Needed when making non blocking
	};
}

#endif