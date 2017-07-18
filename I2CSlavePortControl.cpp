#include "I2CSlavePortControl.h"

using namespace Phantom;

I2CSlavePortControl::I2CSlavePortControl(uint8_t address) {
	this->address = address;
	Wire.begin();
}

void I2CSlavePortControl::digitalWrite(uint8_t pin, bool value) {
	Wire.beginTransmission(this->address);
	Wire.write(pin);
	Wire.write(portType_t(DIGITAL));
	Wire.write(value);
	Wire.endTransmission();
}

void I2CSlavePortControl::analogWrite(uint8_t pin, uint8_t value) {
	Wire.beginTransmission(this->address);
	Wire.write(pin);
	Wire.write(portType_t(ANALOG));
	Wire.write(value);
	Wire.endTransmission();
}