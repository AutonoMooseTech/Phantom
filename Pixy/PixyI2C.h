#ifndef PIXY_I2C_H
#define PIXY_I2C_H

#include "../Phantom.h"
#include "Pixy.h"

class PixyI2C
{
public:
	PixyI2C();
	
	void init();


private:
	uint16_t getWord();
	uint8_t getByte();

	void send(uint8_t* data);
	
};

#endif