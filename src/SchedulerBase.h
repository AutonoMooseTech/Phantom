#ifndef SCHEDULERBASE_H
#define SCHEDULERBASE_H

#include "Phantom.h"

namespace Phantom {
	class SchedulerBase {
	public:
		SchedulerBase();

		virtual void update();
	};
}

#endif