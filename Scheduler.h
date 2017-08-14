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

		void update();
	private:

		struct task_s {
			Base* func;
			uint32_t time;
		};
		
		static std::vector<task_s> tasks; 
	};
}

#endif