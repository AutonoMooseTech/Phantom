#ifndef I2CSLAVEPORTCONTROL_H
#define I2CSLAVEPORTCONTROL_H

#include <Arduino.h>
#include <Wire.h>

namespace Phantom {
	class I2CSlavePortControl {
	public:
		I2CSlavePortControl(uint8_t address);

		void digitalWrite(uint8_t pin, bool value);
		void analogWrite(uint8_t pin, uint8_t value);
	private:
		uint8_t address;

		enum portType_t {DIGITAL, ANALOG};
	};
}
#endif