#include "PCF8574.h"

using namespace Phantom;

PCF8574::PCF8574(uint8_t address): address(address) {

}

void PCF8574::init() {
	Wire.begin();
}

void PCF8574::pinMode(uint8_t pin, uint8_t mode) {
	if(mode == OUTPUT) {
		clearBit(pinModes, pin);
	}
	else {
		setBit(pinModes, pin);
	}
}

void PCF8574::set(uint8_t pin, bool state) {
	if (getBit(pinModes, pin) == OUTPUT) {
		changeBit(shadow, pin, state);
		this->write(shadow);
	}
}

void PCF8574::write(uint8_t value) {
	if(isAvailable()) {
		Wire.beginTransmission(address);
		Wire.write(value & ~(pinModes));
		Wire.endTransmission();
	}
}

bool PCF8574::get(uint8_t pin) {
	return getBit(this->read(), pin);
}

uint8_t PCF8574::read() {
	if (isAvailable()) {
		Wire.requestFrom(address, 1);
		return (Wire.read() & pinModes);
	}
	else return 0;
}

bool PCF8574::isAvailable() {
	Wire.beginTransmission(address);
	return !Wire.endTransmission();
}