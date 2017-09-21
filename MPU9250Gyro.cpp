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

int16_t MPU9250Gyro::get(axis_t axis) {
	switch(axis) {
		case axis_t::X: return aquire(register_t::GYRO_X); break;
		case axis_t::Y: return aquire(register_t::GYRO_Y); break;
		case axis_t::Z: return aquire(register_t::GYRO_Z); break;
	}
}

std::initializer_list<int16_t> MPU9250Gyro::get() {
	return {
		get(axis_t::X),
		get(axis_t::Y),
		get(axis_t::Z)
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
	timeNow = millis();
	int16_t value = get(axis_t(2)) - centers[2];
	if (fabs(value) >= deadbands[2]) {
		readings[2] += value / -16.4 * (timeNow - timeLast) / 1000;
	}
	timeLast = timeNow;
}