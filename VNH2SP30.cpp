#include "VNH2SP30.h"

using namespace Phantom;

VNH2SP30::VNH2SP30(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB): MotorController(pinPWM, pinDirA, pinDirB) {

}

VNH2SP30::VNH2SP30(uint8_t pinPWM, uint8_t pinDirA, uint8_t pinDirB, uint8_t pinEnable): MotorController(pinPWM, pinDirA, pinDirB), pinEnable(pinEnable) {
	
}