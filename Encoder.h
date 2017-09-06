#ifndef ENCODER_H
#define ENCODER_H

#include "Phantom.h"

namespace Phantom {
	class Encoder {
	public:
		enum direction_t {
			FORWARD 	= 1,
			STOPPED 	= 0,
			BACKWARDS 	= -1
		};
		Encoder(uint8_t pinA, uint8_t pinB);

		int32_t get();

		int8_t getDirection();

		void reset();

		void update();
		
		uint8_t pinA;
		uint8_t pinB;
	private:
		int32_t value;
		direction_t direction;

		uint8_t lastState;
		
	};
}

#endif