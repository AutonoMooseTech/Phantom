#include "RobotBase.h"

using namespace Phantom;

RobotBase::RobotBase() {
	// Nothing to do here.
}

void RobotBase::enable() {
	setState(state_t::ENABLED);
}

void RobotBase::disable() {
	setState(state_t::DISABLED);
}

void RobotBase::setState(state_t state) {
	this->state = state;
}

bool RobotBase::stateChanged() {
	return state != stateLast;
}

void RobotBase::setup() {}

void RobotBase::loop() {}

void RobotBase::disabledSetup() {}

void RobotBase::disabledLoop() {}

void RobotBase::enabledSetup() {}

void RobotBase::enabledLoop() {}

void RobotBase::update() {
	scheduler.update();
	if (stateChanged()) {
		switch (state) {
			case state_t::DISABLED: disabledSetup();	break;
			case state_t::ENABLED: 	enabledSetup();		break;
		}
	}
	else {
		switch (state) {
			case state_t::DISABLED: disabledLoop();	break;
			case state_t::ENABLED: 	enabledLoop(); 	break;
		}
	}
	stateLast = this->state;
}