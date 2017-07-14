#ifndef UTILS_H
#define UTILS_H

namespace Phantom {
	namespace Utils {
		inline void pulse(uint8_t pin, uint16_t delta, bool state) {
			digitalWrite(pin, state);
			delay(delta);
			digitalWrite(pin, !state);
		}

		inline float fmap(float input, float inMin, float inMax, float outMin, float outMax) {
			return (input - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
		}
	}
}

#endif