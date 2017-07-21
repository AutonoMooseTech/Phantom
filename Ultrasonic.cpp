#include "Ultrasonic.h"

using namespace Phantom;

Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin): trigPin(trigPin), echoPin(echoPin) {
	pinMode(this->trigPin, OUTPUT);
	pinMode(this->echoPin, INPUT);
}

uint16_t Ultrasonic::get(void) {
	return distance;
}

void Ultrasonic::update(void) {
	// Check for minimum delay since last trigger event
	if (millis() - lastTrig >= trigMinDelta) {
		// Pulse trigger pin
		Utils::pulseHi(this->trigPin, this->trigPulseDelta);
		// Wait unil signal goes high
		while(!digitalRead(this->echoPin)); // Todo: add timeouts
		// Remember start time
		uint32_t startTime = micros();
		// Wait while signal is high
		while(digitalRead(this->echoPin)); // Todo: add imeouts
		// Return calculated value in mm
		this->distance = Utils::delta(micros(), startTime) / 5.8f;
	}
}