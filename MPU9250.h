#ifndef MPU9250_H
#define MPU9250_H

#include <Arduino.h>
#include "Phantom.h"
#include "SensorBase.h"
#include <Wire.h>

namespace Phantom {
	class MPU9250 {
	public:
		MPU9250(uint8_t address);

		enum register_t {
			ACCEL_X,
			ACCEL_Y,
			ACCEL_Z,
			GYRO_X,
			GYRO_Y,
			GYRO_Z,
			TEMP
		};

		void initI2C();

		int16_t aquire(uint8_t reg);
		int16_t aquire(register_t reg);

		

	private:
		uint8_t address;
	};
}

#endif