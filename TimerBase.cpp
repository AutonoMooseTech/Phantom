#include "TimerBase.h"

using namespace Phantom;

TimerBase::TimerBase(uint32_t interval): prevTime(0), updateTime(interval) {
	// Nothing to see here.
}

void TimerBase::force() {
	prevTime = millis();
	doWork();
}

void TimerBase::update() {
	// Sentinel
	currTime = millis();
	if(currTime - prevTime < updateTime) return;
	prevTime = currTime;

	doWork();
}