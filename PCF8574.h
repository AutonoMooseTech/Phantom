#ifndef PCF8574_H
#define PCF8574_H

#include "Phantom.h"
#include <Wire.h>

namespace Phantom {
	class PCF8574
	{
	public:
		PCF8574(uint8_t address);
		
		void init();

		void pinMode(uint8_t pin, uint8_t mode);

		void set(uint8_t pin, bool state);
		void write(uint8_t value);

		bool get(uint8_t pin);
		uint8_t read();
	private:
		uint8_t address;
		uint8_t shadow;
		uint8_t pinModes = 0xFF; // default to inputs

		bool isAvailable();
	};
}

#endif