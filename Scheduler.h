#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Arduino.h>
#include <StandardCplusplus.h>
#include <vector>
#include "Phantom.h"
#include "Base.h"

namespace Phantom {
	class Scheduler {
	public:
		Scheduler();

		void add(Base* func, uint32_t time);

		void clearAll();

		void clear(Base* func);

		void update();

	private:
		static std::vector<std::pair<Base*, uint32_t>> tasks;
		 
	};
}

#endif