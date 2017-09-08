#ifndef DIGITALOUTPUT_H
#define DIGITALOUTPUT_H

#include "Phantom.h"

namespace Phantom {
	class DigitalOutput {
	public:
		DigitalOutput(uint8_t pin);
		
		void set(bool state);
	private:
		uint8_t pin;
	};
}

#endif