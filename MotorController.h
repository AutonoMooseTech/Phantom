#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Arduino.h>
#include "Phantom.h"

namespace Phantom {
	class MotorController {
	public:
		MotorController(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB);

		void set(float value);

		void setMin(uint8_t min);
		void setMax(uint8_t max);
		void setBounds(uint8_t min, uint8_t max);

		void disable();

		void update();
	private:
		uint8_t pinPWM, pinDirA, pinDirB, pinEnable; // Pinout
		float value = 0.0f;
		bool enabled = true;

		// Bounds
		uint8_t min = 0;
		uint8_t max = 255;
	};
}

#endif