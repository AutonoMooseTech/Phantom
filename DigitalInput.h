#ifndef DIGITALINPUT_H
#define DIGITALINPUT_H

#include "Phantom.h"

namespace Phantom {
	class DigitalInput {
	public:
		DigitalInput(uint8_t pin);
		DigitalInput(uint8_t pin, bool inputPullup);
		
		bool get();
	private:
		uint8_t pin;
	};
}

#endif