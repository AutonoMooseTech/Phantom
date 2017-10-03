#include "L298.h"

using namespace Phantom;

L298::L298(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB): MotorController(pinPWM, pinDirA, pinDirB) {
	
}