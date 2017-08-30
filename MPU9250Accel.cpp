#include "MPU9250Accel.h"

using namespace Phantom;

MPU9250Accel::MPU9250Accel(uint8_t address): MPU9250(address), address(address) {

}

void MPU9250Accel::init() {
	initI2C();
}

int16_t MPU9250Accel::get(axis_t axis) {
	switch(axis) {
		case axis_t::X: return aquire(register_t::ACCEL_X); break;
		case axis_t::Y: return aquire(register_t::ACCEL_Y); break;
		case axis_t::Z: return aquire(register_t::ACCEL_Z); break;
	}
}

std::initializer_list<int16_t> MPU9250Accel::get() {
	return {
		get(axis_t::X),
		get(axis_t::Y),
		get(axis_t::Z)
	};
}

int16_t MPU9250Accel::getX() {
	return get(axis_t::X);
}

int16_t MPU9250Accel::getY() {
	return get(axis_t::Y);
}

int16_t MPU9250Accel::getZ() {
	return get(axis_t::Z);
}