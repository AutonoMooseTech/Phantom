#ifndef OMNIDRIVE_H
#define OMNIDRIVE_H

#include <Arduino.h>
#include "Phantom.h"
#include "MotorController.h"

namespace Phantom {
	class OmniDrive {
	public:
		OmniDrive(MotorController& motorA, MotorController& motorB, MotorController& motorC, MotorController& motorD);

		void set(float direction, float magnitude);
		void set(float direction, float magnitude, float rotation);

		void setGlobal(bool global);

	private:
		MotorController& motorA;
		MotorController& motorB;
		MotorController& motorC;
		MotorController& motorD;

		float direction;
		float magnitude;
		float rotation;

		bool global;

		float xMagnitude, yMagnitude;
		float motorSpeedA, motorSpeedB, motorSpeedC, motorSpeedD;
		float maxPower;
	};
}

#endif