#ifndef UTILS_H
#define UTILS_H

namespace Phantom {
	namespace Utils {
		void pulseHIGH(uint8_t pin, uint16_t delta, bool state) {
			digitalWrite(pin, state);
			delay(delta);
			digitalWrite(pin, !state);
		}
	}
}

#endif