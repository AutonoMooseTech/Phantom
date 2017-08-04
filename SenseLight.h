#ifndef SENSELIGHT_H
#define SENSELIGHT_H

#include <Arduino.h>
#include "Phantom.h"

namespace Phantom {
	class SenseLight {
	public:
		SenseLight(uint8_t pinAnalogIn);
		SenseLight(uint8_t pinAnalogIn, uint8_t pinLightOut);

		float get();

		void update();
	private:
		uint8_t pinAnalogIn, pinLightOut;
		float value;
	};
}

#endif