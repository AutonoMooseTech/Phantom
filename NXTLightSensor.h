#ifndef NXTLIGHTSENSOR_H
#define NXTLIGHTSENSOR_H

#include "Phantom.h"
#include "Base.h"
#include "Scheduler.h"

namespace Phantom {
	class NXTLightSensor: virtual public Base, public Scheduler {
	public:
		NXTLightSensor(uint8_t pinInput);
		NXTLightSensor(uint8_t pinInput, uint8_t pinLed);

		float get();

		void led(bool state);

		void update();
	private:
		uint8_t pinInput, pinLed;
		float lightValue;
		bool ledState = LOW;
		bool ledStateLast = HIGH;	
	};

}


#endif