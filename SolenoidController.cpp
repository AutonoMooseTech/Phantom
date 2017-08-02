#include "SolenoidController.h"

using namespace Phantom;

SolenoidController::SolenoidController(uint8_t pinTrigger): pinTrigger(pinTrigger) {
	pinMode(pinTrigger, OUTPUT);
}

SolenoidController::SolenoidController(uint8_t pinTrigger, uint8_t pinVoltSense): pinTrigger(pinTrigger), pinVoltSense(pinVoltSense) {
	pinMode(pinTrigger, OUTPUT);
	pinMode(pinVoltSense, INPUT);
}

void SolenoidController::trigger() {
	state = state_t::ON;
}

void SolenoidController::forceOff() {
	state = state_t::OFF;
}

void SolenoidController::setDuration(uint16_t time) {
	duration = time;
}

void SolenoidController::update() {
	if (state == state_t::ON) {
		if (stateLast == state_t::OFF) { // state changed from off to on
			timeOfTrigger = millis();
			digitalWrite(pinTrigger, HIGH);
		}
		else if (millis() - timeOfTrigger >= duration) { // state is on, but over timeout duration
			state = state_t::OFF;
			digitalWrite(pinTrigger, LOW);
		}
	}
}