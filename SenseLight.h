#ifndef SENSELIGHT_H
#define SENSELIGHT_H

#include "Phantom.h"

namespace Phantom {
	class SenseLight {
	public:
		SenseLight(uint8_t pinAnalogIn);

		float get();
	private:
		uint8_t pinAnalogIn;
		float value;
	};
}

#endif