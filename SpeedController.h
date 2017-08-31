#ifndef SPEEDCONTROLLER_H
#define SPEEDCONTROLLER_H

#include "Phantom.h"
#include "MotorBase.h"

namespace Phantom {
	class SpeedController: public MotorBase {
	public:
		SpeedController(uint8_t pinOutput);

		void set(float speed);

		void setBounds(uint8_t min, uint8_t center, uint8_t max);
		void setBounds(uint8_t min, uint8_t deadbandMin, uint8_t center, uint8_t deadbandMax, uint8_t max);
	private:
		uint8_t pinOutput;
		uint8_t min, deadbandMin, center, deadbandMax, max;
	};
}

#endif