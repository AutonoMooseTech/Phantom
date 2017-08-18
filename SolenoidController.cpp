#include "SolenoidController.h"

using namespace Phantom;

SolenoidController::SolenoidController(uint8_t pinTrigger):
	Scheduler(),
	pinTrigger(pinTrigger) {
	pinMode(pinTrigger, OUTPUT);
}

void SolenoidController::trigger() {
	state = state_t::ON;
	add(this, duration); // Add to scheduler
	update();
}

void SolenoidController::forceOff() {
	state = state_t::OFF;
	clear(this); // Remove any instances from scheduler
	update(); 
}

void SolenoidController::setDuration(uint16_t time) {
	duration = time;
}

void SolenoidController::update() {
	digitalWrite(pinTrigger, state == state_t::ON and stateLast == state_t::OFF);
}