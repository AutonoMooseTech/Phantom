#ifndef NXTLIGHTSENSOR_H
#define NXTLIGHTSENSOR_H

#include "Phantom.h"

namespace Phantom {
	class NXTLightSensor {
	public:
		NXTLightSensor(uint8_t pinInput);
		NXTLightSensor(uint8_t pinInput, uint8_t pinLed);

		float get();

		void led(bool state);
	private:
		uint8_t pinInput, pinLed;
	};

}


#endif