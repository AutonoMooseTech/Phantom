#include "Watchdog.h"

using namespace Phantom;

Watchdog::Watchdog(uint32_t timeout): timeout(timeout) {
}

void Watchdog::pat() {
	lastTime = millis();
}

void Watchdog::check() {
	if (delta(millis(), lastTime) > timeout) {
		for (auto i = instances.begin(); i < instances.end(); i++) {
			i->disable();
		}
	}
}

void Watchdog::addInstance(std::initializer_list<MotorController> iList) {
	for (auto i = iList.begin(); i < iList.end(); i++) {
		instances.push_back(*i);
	}
}

void Watchdog::addInstance(MotorController instance) {
	instances.push_back(instance);
}