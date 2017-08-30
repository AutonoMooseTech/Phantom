#ifndef SENSORBASE_H
#define SENSORBASE_H

namespace Phantom {
	class SensorBase {
	public:
		SensorBase();
		
		virtual float get();
	};
}

#endif