#include "MPU9250Gyro.h"

using namespace Phantom;

MPU9250Gyro::MPU9250Gyro(uint8_t address): MPU9250(address), address(address) {

}

void MPU9250Gyro::init() {
	initI2C();
	// Change sensitivity
	Wire.beginTransmission(address);
	Wire.write(0x1B);
	Wire.write(0b00011000);
	Wire.endTransmission();
}

void MPU9250Gyro::callibrate() {
}

void MPU9250Gyro::reset() {
	readings[0] = 0;
	readings[1] = 0;
	readings[2] = 0;
}

int16_t MPU9250Gyro::getRaw(axis_t axis) {
	switch(axis) {
		case axis_t::X: return aquire(register_t::GYRO_X); break;
		case axis_t::Y: return aquire(register_t::GYRO_Y); break;
		case axis_t::Z: return aquire(register_t::GYRO_Z); break;
	}
}

std::initializer_list<int16_t> MPU9250Gyro::get() {
	return {
		readings[axis_t::X],
		readings[axis_t::Y],
		readings[axis_t::Z]
	};
}

int16_t MPU9250Gyro::getX() {
	return readings[axis_t::X];
}

int16_t MPU9250Gyro::getY() {
	return readings[axis_t::Y];
}

float MPU9250Gyro::getZ() {
	return readings[axis_t::Z];
}

void MPU9250Gyro::update() {
	uint32_t currentTime = millis();
	for (int i = axis_t::X; i <= axis_t::Z; i++) {
		int16_t value = getRaw(axis_t(i)) - centers[i];
		if (fabs(value) >= deadband) {
			readings[i] += value / -16.4 * (currentTime - timeLast) / 1000;
		}
	}
	timeLast = currentTime;
}