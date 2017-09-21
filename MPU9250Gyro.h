#ifndef MPU9250GYRO_H
#define MPU9250GYRO_H

#include "Phantom.h"
#include "MPU9250.h"
#include <initializer_list>

namespace Phantom {
	class MPU9250Gyro: private MPU9250 {
	public:
		MPU9250Gyro(uint8_t address);

		enum axis_t {
			X = 0,
			Y = 1,
			Z = 2
		};
		
		void init();

		void callibrate();

		void reset();

		int16_t get(axis_t axis);

		std::initializer_list<int16_t> get();

		int16_t getX();
		int16_t getY();
		float getZ();

		void update();
		int16_t centers[3] = {0, 0, -17};
	private:
		uint8_t address;
		
		int16_t deadbands[3] = {50, 50, 50};
		float readings[3] = {0.0, 0.0, 0.0};

		uint32_t timeLast = millis();
		uint32_t timeNow = 0;
	};
}

#endif