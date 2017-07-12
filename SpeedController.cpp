#include "SpeedController.h"

using namespace Phantom;

SpeedController::SpeedController(uint8_t pin): _pin {
	pinMode(_pin, OUTPUT);
}

SpeedController::floatToUnsignedByte(float value) {
	return return (value + 1) * 255 / 2;
}

void SpeedController::set(float value) {
	_value = floatToUnsignedByte(value);
	if (_value >= _mid - (deadband / 2) and _value <= _mid + (deadband / 2)) {
		_value = _mid;
	}
	else {
		_value = constrain(_value, _min, _max);
	}
}

void SpeedController::get() {
	return _value;
}

// Bounds

void SpeedController::min(float value) {
	_min = floatToUnsignedByte(value);
}

void SpeedController::min(uint8_t value) {
	_min = value;
}

void SpeedController::mid(float value) {
	_mid = floatToUnsignedByte(value);
}

void SpeedController::mid(float value) {
	_mid = value;
}


void SpeedController::max(float value) {
	_max = floatToUnsignedByte(value);
}

void SpeedController::max(uint8_t value) {
	_max = value;
}

void SpeedController::deadband(float value) {
	_deadband = floatToUnsignedByte(value);
}

void SpeedController::deadband(float value) {
	_deadband = value;
}


// Refresh

void SpeedController::refresh() {
	analogWrite(_pin, floatToUnsignedByte(_value));
}