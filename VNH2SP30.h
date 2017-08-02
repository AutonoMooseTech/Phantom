#ifndef VNH2SP30_H
#define VNH2SP30_H

#include <Arduino.h>
#include "Utils.h"
#include "MotorController.h"

namespace Phantom {
	class VNH2SP30: public MotorController {
	public:
		VNH2SP30(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB);
		VNH2SP30(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB, uint8_t pinEnable);

		void set(float value);
		float get();
	private:
		uint8_t pinEnable;
	};
}

#endif