#ifndef MPU9250GYRO_H
#define MPU9250GYRO_H

#include "Phantom.h"
#include "MPU9250.h"
#include "Scheduler.h"
#include "SchedulerBase.h"
#include <initializer_list>

namespace Phantom {
	class MPU9250Gyro: private MPU9250, private SchedulerBase {
	public:
		Scheduler scheduler;

		MPU9250Gyro(uint8_t address);

		enum axis_t {
			X = 0,
			Y = 1,
			Z = 2
		};
		
		void init();

		void reset();

		std::initializer_list<int16_t> get();

		float getX();
		float getY();
		float getZ();

		
	private:
		void update();

		int16_t getRaw(axis_t axis);


		uint8_t address;
		
		int16_t deadband = 50;
		int16_t centers[3] = {0, 0, -17};

		float readings[3];

		uint32_t timeLast = millis();
	};
}

#endif