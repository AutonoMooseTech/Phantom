#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include "Utils.h"

class MotorController {
public:
	MotorController(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB);

	void set(float value);
	float get();

	void update();
private:
	uint8_t pinPWM, pinDirA, pinDirB; // Pinout
	float value;
};

#endif