#ifndef SENSELIGHT_H
#define SENSELIGHT_H

#include <Arduino.h>
#include "Phantom.h"

namespace Phantom {
	class SenseLight {
	public:
		SenseLight(uint8_t pinAnalogIn);

		float get();

		void update();
	private:
		uint8_t pinAnalogIn;
		float value;
	};
}

#endif