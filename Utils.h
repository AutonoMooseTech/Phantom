#ifndef UTILS_H
#define UTILS_H

namespace Phantom {
	namespace Utils {
		void pulseHIGH(uint8_t pin, uint16_t delta, bool state) {
			digitalWrite(pin, state);
			delay(delta);
			digitalWrite(pin, !state);
		}

		 void fmap(float input, float inMin, float inMax, float outMin, float outMax) {
		 	return (input - inMin) * (outMax - outMin) / (in_max - in_min) + outMin;
		 }
	}
}

#endif