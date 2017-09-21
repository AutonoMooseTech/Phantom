#ifndef NXTTOUCHSENSOR_H
#define NXTTOUCHSENSOR_H

#include <Arduino.h>
#include "Phantom.h"
#include "Base.h"
#include "Scheduler.h"

namespace Phantom {
	class NXTTouchSensor {
	public:
		NXTTouchSensor(uint8_t pinInput);
		
		float get();

		void update();

	private:
		uint8_t pinInput;
		bool state;
	};
}


#endif