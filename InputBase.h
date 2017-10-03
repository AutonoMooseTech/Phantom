#ifndef INPUTBASE_H
#define INPUTBASE_H

#include "Phantom.h"

namespace Phantom {
	class InputBase {
	public:
		InputBase();
		
		template <typename T>
		T get();		
	};
}

#endif