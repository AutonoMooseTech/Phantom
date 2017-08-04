#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>
#include "Phantom.h"

/*
	   NO   NC
ON     HIGH LOW
OFF    LOW  HIGH
*/

namespace Phantom {
	class Relay {
	public:
		enum type_t {NO = 0, NC = 1};

		Relay(uint8_t pin, type_t type);

		void on();
		void off();

		void setState(bool state);

		void update();
	private:
		uint8_t pin;
		type_t type;

		bool state;
	};
}

#endif