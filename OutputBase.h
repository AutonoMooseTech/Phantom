#ifndef OUTPUTBASE_H
#define OUTPUTBASE_H

#include "Phantom.h"

namespace Phantom {
	class OutputBase {
	public:
		OutputBase();
		
		template <typename T>
		void set(T value);
	};
}

#endif