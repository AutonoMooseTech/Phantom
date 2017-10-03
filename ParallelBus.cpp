#include "ParallelBus.h"

using namespace Phantom;

ParallelBus::ParallelBus(std::initializer_list<uint8_t> const & pins):
	width(width),
	pins(pins) {

}

uint32_t ParallelBus::get() {
	uint32_t data;
	for (auto i = pins.begin(); i != pins.end(); i++) {
		changeBit(data, *i, digitalRead(pins[i]));
	}
	return data;
}


bool ParallelBus::getBit(uint8_t n) {
	return digitalRead(pins[n]);
}