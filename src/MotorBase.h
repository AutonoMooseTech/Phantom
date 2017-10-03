#ifndef MOTORBASE_H
#define MOTORBASE_H

#include "Phantom.h"
#include "OutputBase.h"

namespace Phantom {
	class MotorBase: public OutputBase {
	public:
		MotorBase();

		virtual void set(float speed);
		virtual void disable();
	};
}

#endif