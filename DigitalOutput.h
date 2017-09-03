#ifndef DIGITALOUTPUT_H
#define DIGITALOUTPUT_H

#include "Phantom.h"

namespace Phantom {
	class DigitalOutput {
	public:
		enum state_t {
			LOW,
			HIGH
		};

		DigitalOutput(uint8_t pin);
		
		void set(bool state);
		void set(state_t state);
	private:
		uint8_t pin;
	};
}

#endif