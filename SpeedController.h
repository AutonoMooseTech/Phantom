#ifndef SPEEDCONTROLLER_H
#define SPEEDCONTROLLER_H

#include <Arduino.h>
#include "Phantom.h"

namespace Phantom {
	class SpeedController {
	public:
		SpeedController(uint8_t pinOutput);

		void set(float speed);

		void setBounds(uint8_t min, uint8_t center, uint8_t max);
		void setBounds(uint8_t min, uint8_t deadbandMin, uint8_t center, uint8_t deadbandMax, uint8_t max);
		
		void update();
	private:
		uint8_t pinOutput;

		float speed = 0.0f;

		// Bounds
		uint8_t min;
		uint8_t deadbandMin;
		uint8_t	center;
		uint8_t	deadbandMax;
		uint8_t max;
	};
}

#endif