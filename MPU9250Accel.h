#ifndef MPU9250ACCEL_H
#define MPU9250ACCEL_H

#include "Phantom.h"
#include "MPU9250.h"
#include <initializer_list>

namespace Phantom {
	class MPU9250Accel: private MPU9250 {
	public:
		MPU9250Accel(uint8_t address);

		enum axis_t {
			X = 0,
			Y = 1,
			Z = 2
		};
		
		void init();

		//void zero(); // Todo

		int16_t get(axis_t axis);

		std::initializer_list<int16_t> get();

		int16_t getX();
		int16_t getY();
		int16_t getZ();
	};
}

#endif