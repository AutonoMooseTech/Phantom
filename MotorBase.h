#ifndef MOTORBASE_H
#define MOTORBASE_H

#include "Phantom.h"

namespace Phantom {
	class MotorBase {
	public:
		MotorBase();

		virtual void set(float speed);
		virtual void disable();
	};
}

#endif