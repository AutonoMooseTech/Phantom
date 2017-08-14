#include "Scheduler.h"

using namespace Phantom;

Scheduler::Scheduler() {

}

void Scheduler::add(Base* func, uint32_t time) {
	tasks.push_back({func, millis() + time});
}

void Scheduler::clear() {
	tasks.clear();
}

void Scheduler::update() {
	for (auto i = tasks.begin(); i != tasks.end(); i++) {
		auto task = (*i);
		if (task.time <= millis()) {
			task.func->update(); // Run
			tasks.erase(i); // Erase this item as it is no longer needed
		}
	}
}