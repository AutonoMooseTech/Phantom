#ifndef SOLENOIDCONTROLLER_H
#define SOLENOIDCONTROLLER_H

#include <Arduino.h>
#include "Phantom.h"
#include "Base.h"
#include "Scheduler.h"

namespace Phantom {
	class SolenoidController:
		virtual public Base,
		virtual private Scheduler {
	public:
		SolenoidController(uint8_t pinTrigger);
		
		void trigger();
		void forceOff();

		void setDuration(uint16_t time);

		void update();
	private:
		uint8_t pinTrigger;
		uint16_t duration = 100; // in ms

		enum state_t {OFF = LOW, ON = HIGH};
		state_t state = state_t::OFF;
		state_t stateLast = state_t::OFF;
	};
}

#endif