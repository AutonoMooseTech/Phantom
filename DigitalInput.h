#ifndef DIGITALINPUT_H
#define DIGITALINPUT_H

#include "Phantom.h"

namespace Phantom {
	class DigitalInput {
	public:
		DigitalInput(uint8_t pin);
		
		bool get();

		void setPullup(bool state);
	private:
		uint8_t pin;
	};
}

#endif