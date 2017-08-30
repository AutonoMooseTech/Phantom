#include "MPU9250Gyro.h"

using namespace Phantom;

MPU9250Gyro::MPU9250Gyro(uint8_t address): MPU9250(address), address(address) {

}

void MPU9250Gyro::init() {
	initI2C();
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
	return get(axis_t::X);
}

int16_t MPU9250Gyro::getY() {
	return get(axis_t::Y);
}

int16_t MPU9250Gyro::getZ() {
	return get(axis_t::Z);
}