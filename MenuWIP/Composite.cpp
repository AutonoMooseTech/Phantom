#include "Composite.h"

using namespace Phantom;

Composite::Composite(): Leaf() {

}

void Composite::add(Leaf* leaf) {
	children.push_back(leaf);
}

void Composite::remove(Leaf* leaf) {
	children.erase(std::remove(children.begin(), children.end(), leaf), children.end());
}

Leaf* Composite::getChild(int index) {
	return children[index];
}