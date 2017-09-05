#ifndef OMNIDRIVE_H
#define OMNIDRIVE_H

#include "Phantom.h"
#include "MotorBase.h"
#include <algorithm>
#include <initializer_list>

namespace Phantom {
	class OmniDrive {
	public:
		OmniDrive(MotorBase& motorA, MotorBase& motorB, MotorBase& motorC, MotorBase& motorD);

		void set(float direction, float magnitude);
		void set(float direction, float magnitude, float rotation);

		void setGlobal(bool global);

	private:
		MotorBase& motorA;
		MotorBase& motorB;
		MotorBase& motorC;
		MotorBase& motorD;

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