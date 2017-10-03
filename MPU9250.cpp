#include "MPU9250.h"

using namespace Phantom;

MPU9250::MPU9250(uint8_t address): address(address) {
}

void MPU9250::initI2C() {
	Wire.begin();

	// Power management (wake up)
	Wire.beginTransmission(address);
	Wire.write(0x6B);
	Wire.write(0);
	Wire.endTransmission(true);
}

int16_t MPU9250::aquire(register_t reg) {
	Wire.beginTransmission(address);
	switch(reg) {
		case register_t::ACCEL_X: 	Wire.write(0x3B); break;
		case register_t::ACCEL_Y: 	Wire.write(0x3D); break;
		case register_t::ACCEL_Z: 	Wire.write(0x3F); break;
		case register_t::GYRO_X: 	Wire.write(0x43); break;
		case register_t::GYRO_Y: 	Wire.write(0x45); break;
		case register_t::GYRO_Z: 	Wire.write(0x47); break;
		case register_t::TEMP: 		Wire.write(0x41); break;
	}
	Wire.endTransmission(false);

	Wire.requestFrom(this->address, 2, true);
	
	return (Wire.read() << 8 | Wire.read());
}