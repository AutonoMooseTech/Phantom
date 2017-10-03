#ifndef L298_H
#define L298_H

#include <Arduino.h>
#include "Phantom.h"
#include "MotorController.h"

namespace Phantom {
	class L298: public MotorController {
	public:
		explicit L298(uint8_t pinPwm, uint8_t pinDirA, uint8_t pinDirB);
	};
}

#endif