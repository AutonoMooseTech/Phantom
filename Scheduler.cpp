#include "Scheduler.h"

using namespace Phantom;

Scheduler::Scheduler() {

}

void Scheduler::add(Base* func, uint32_t time) {
	tasks.push_back({func, millis() + time});
}

void Scheduler::clearAll() {
	tasks.clear();
}

void Scheduler::clear(Base* func) {
	// Iterate through entries and clear ones with matching class
	for (auto i = tasks.begin(); i != tasks.end(); i++) {
		auto task = (*i);
		if (task.func == func) {
			tasks.erase(i);
		}
	}
}

void Scheduler::update() {
	// Iterate through entries and run tasks that have reached their wait time
	for (auto i = tasks.begin(); i != tasks.end(); i++) {
		auto task = (*i);
		if (task.time <= millis()) {
			task.func->update(); // Run
			tasks.erase(i); // Erase this item as it is no longer needed
		}
	}
}