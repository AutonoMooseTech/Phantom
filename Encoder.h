#ifndef ENCODER_H
#define ENCODER_H

#include "Phantom.h"

namespace Phantom {
	class Encoder {
	public:
		enum type_t {
			X1 = 1,
			X2 = 2,
			X4 = 4
		};

		enum direction_t {
			FORWARD 	= 1,
			STOPPED 	= 0,
			BACKWARDS 	= -1
		};

		Encoder(uint8_t pinA, uint8_t pinB);
		Encoder(uint8_t pinA, uint8_t pinB, type_t type);

		int32_t get();

		int8_t getDirection();

		bool getChanged();

		void reset();

		void update();
		
		uint8_t pinA;
		uint8_t pinB;
	private:
		type_t type = type_t::X4;

		int32_t value;
		direction_t direction;
		bool changed = false;

		uint8_t lastState;
	};
}

#endif