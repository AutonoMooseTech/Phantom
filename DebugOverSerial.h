#ifndef DEBUGOVERSERIAL_H
#define DEBUGOVERSERIAL_H

#include <Arduino.h>
#include "Utils.h"

namespace Phantom {
	class DebugOverSerial
	{
	public:
		DebugOverSerial(uint16_t baud);
		
		// Control
		void enable(void);
		void disable(void);

		// Display
		void print(String input);
		void println(String input); // Automatic line ending
		void printTitle(String input);
	private:
		uint16_t baud;
		bool enabled = true;
	};
}

#endif