#ifndef NXTLIGHTSENSOR_H
#define NXTLIGHTSENSOR_H

#include <Arduino.h>
#include <Phantom.h>

namespace Phantom {
	class NXTLightSensor
	{
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