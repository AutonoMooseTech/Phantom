#ifndef SENSORBASE_H
#define SENSORBASE_H

#include "Phantom.h"

namespace Phantom {
	class SensorBase {
	public:
		SensorBase();
		
		virtual float get();
	};
}

#endif