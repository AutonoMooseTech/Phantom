#ifndef SPEEDCONROLLER_H
#define SPEEDCONROLLER_H

#include "Arduino.h"

namespace Phantom {
	class SpeedController {
	private:
		uint8_t _pin;
		float _value;

		// Bounds
		uint8_t _min = 0;
		uint8_t _deadband = 0;
		uint8_t _max = 0;

		uint8_t floatToUnsignedByte(float value);
	public:
		SpeedController(uint8_t pin);
		
		void set(float value);
		float get();

		void min(float value);
		void min(uint8_t value);

		void mid(float value);
		void mid(uint8_t value);

		void max(float value);
		void max(uint8_t value);

		void deadband(float value);
		void deadband(uint8_t value);

		void refresh();
	}
}


#endif