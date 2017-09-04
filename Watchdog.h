#ifndef WATCHDOG_H
#define WATCHDOG_H

#include "Phantom.h"
#include "MotorBase.h"
#include <initializer_list>
#include <vector>

namespace Phantom {
	class Watchdog {
	public:
		Watchdog(uint32_t timeout);

		void pat(); // Pat the doggo

		void addInstance(std::initializer_list<MotorBase> iList);
		void addInstance(MotorBase instance);

		void check();
	private:
		uint32_t timeout;
		uint32_t lastTime;
		std::vector<MotorBase> instances;
	};
}

#endif