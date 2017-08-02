#ifndef SOLENOIDCONTROLLER_H
#define SOLENOIDCONTROLLER_H

#include <Arduino.h>

namespace Phantom {
	class SolenoidController {
	public:
		SolenoidController(uint8_t pinTrigger);
		SolenoidController(uint8_t pinTrigger, uint8_t pinVoltSense);
		
		void trigger();
		void forceOff();

		void setDuration(uint16_t time);

		void update();
	private:
		uint8_t pinTrigger, pinVoltSense;
		uint16_t duration = 100; // in ms

		enum state_t {OFF, ON};
		state_t state = state_t::OFF;
		state_t stateLast = state_t::OFF;

		uint32_t timeOfTrigger;
	};
}

#endif