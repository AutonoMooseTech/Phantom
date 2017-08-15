#ifndef NXTTOUCHSENSOR_H
#define NXTTOUCHSENSOR_H

#include <Arduino.h>
#include "../Phantom.h"
#include "../Base.h"
#include "../Scheduler.h"

namespace Phantom {
	class NXTTouchSensor: virtual public Base, virtual public Scheduler {
	public:
		NXTTouchSensor(uint8_t pinInput);
		
		void get();

		void update();

	private:
		uint8_t pinInput;
		bool state;
	};
}


#endif