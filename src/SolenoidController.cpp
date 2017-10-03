#include "SolenoidController.h"

using namespace Phantom;

SolenoidController::SolenoidController(uint8_t pinTrigger):
	SchedulerBase(),
	pinTrigger(pinTrigger),
	scheduler() {
	pinMode(pinTrigger, OUTPUT);
}

void SolenoidController::trigger() {
	state = state_t::ON;
	stateLast = state_t::OFF;
	scheduler.add(this, duration); // Add to schedulers
	update();
}

void SolenoidController::forceOff() {
	state = state_t::OFF;
	scheduler.clear(this); // Remove any instances from scheduler
	update(); 
}

void SolenoidController::setDuration(uint16_t time) {
	duration = time;
}

void SolenoidController::update() {
	digitalWrite(pinTrigger, state and !stateLast); // Write output
	stateLast = state;
}