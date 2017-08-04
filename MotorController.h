#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Arduino.h>
#include "Phantom.h"

namespace Phantom {
	class MotorController {
	public:
		MotorController(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB);

		void set(float value);

		void disable();

		void update();
	private:
		uint8_t pinPWM, pinDirA, pinDirB, pinEnable; // Pinout
		float value = 0.0f;
		bool enabled = true;
	};
}

#endif