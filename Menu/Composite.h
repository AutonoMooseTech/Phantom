#ifndef MENU_COMPOSITE_H
#define MENU_COMPOSITE_H

#include "../Phantom.h"
#include "Leaf.h"

namespace Phantom {
	class Composite: public Leaf {
	public:
		Composite();

		void add(Leaf leaf);
		void remove(Leaf leaf);
		Leaf* getChild();

	private:
		std::vector<Leaf*> children;
	};
}

#endif