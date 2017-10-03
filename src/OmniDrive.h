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

		void set(float direction, float magnitude, float angle);

	private:
		MotorBase& motorA;
		MotorBase& motorB;
		MotorBase& motorC;
		MotorBase& motorD;
	};
}

#endif