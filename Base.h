#ifndef BASE_H
#define BASE_H

#include <Arduino.h>
#include "Phantom.h"

namespace Phantom {
	class Base {
	public:
		Base();

		virtual void update();
	};
}

#endif