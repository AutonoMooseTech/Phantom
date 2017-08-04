#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Arduino.h>
#include "Utils.h"

namespace Phantom {
	class MotorController {
	public:
		MotorController(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB);

		void setValue(float value);
		float getValue();

		void enable();

		void update();
	private:
		uint8_t pinPWM, pinDirA, pinDirB, pinEnable; // Pinout
		float value = 0.0f;
		bool enabled = true;
	};
}

#endif