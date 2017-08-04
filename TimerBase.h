/*
Originally authored by Simon Hogwood.
*/

#ifndef TIMERBASE_H
#define TIMERBASE_H

#include <Arduino.h>
#include "Phantom.h"

namespace Phantom {
	class TimerBase {
	private:
		uint32_t currTime, prevTime, updateTime;

	public:
		TimerBase(uint32_t interval = 100);

		void force();

		void update(void);

		virtual void doWork(void) = 0;
	};
}

#endif