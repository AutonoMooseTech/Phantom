#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Phantom.h"
#include <vector>
#include "SchedulerBase.h"

namespace Phantom {
	class Scheduler {
	public:
		Scheduler();

		void add(SchedulerBase* func, uint32_t time);

		void clearAll();

		void clear(SchedulerBase* func);

		void update();

	private:
		static std::vector<std::pair<SchedulerBase*, uint32_t>> tasks;
		 
	};
}

#endif