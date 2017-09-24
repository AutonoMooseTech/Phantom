#ifndef SOLENOIDCONTROLLER_H
#define SOLENOIDCONTROLLER_H

#include "Phantom.h"
#include "SchedulerBase.h"
#include "Scheduler.h"

namespace Phantom {
	class SolenoidController:
		virtual public SchedulerBase {
	public:
		SolenoidController(uint8_t pinTrigger);
		
		void trigger(); // Set the solenoid to ON
		void forceOff(); // Force solenoid to OFF

		void setDuration(uint16_t time); // Set maximum ON time

		void update();
	private:
		Scheduler scheduler;
		uint8_t pinTrigger; // Output pin
		uint16_t duration = 100; // in ms

		enum state_t {OFF = LOW, ON = HIGH};
		state_t state = state_t::OFF;
		state_t stateLast = state_t::OFF;
	};
}

#endif