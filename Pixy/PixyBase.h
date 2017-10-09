#ifndef PIXY_BASE_H
#define PIXY_BASE_H

#include "../Phantom.h"


namespace Phantom {
	class PixyBase {
	public:
		struct Block() {
			uint16_t signature;
			uint16_t x;
			uint16_t y;
			uint16_t width;
			uint16_t height;
			uint16_t angle; // CC only.
		};

		PixyBase();
		~PixyBase();

		void init();
		
		void aquireBlocks();

		void setServos(uint16_t s0, uint16_t s1);

		void setBrightness(uint8_t brightness);

		void setLED(uint8_t r, uint8_t g, uint8_t b);

	private:
		Block *blocks;
	};
}

#endif