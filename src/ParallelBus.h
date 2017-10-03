#ifndef PARALLELBUS_H
#define PARALLELBUS_H

#include <Phantom.h>
#include <initializer_list>
#include <vector>

namespace Phantom {
	class ParallelBus {
	public:
		ParallelBus(std::initializer_list<uint8_t> const & pins);

		uint32_t get();

		bool getBit(uint8_t n);

	private:
		uint8_t width;
		std::vector<uint8_t> pins;
	};
}

#endif