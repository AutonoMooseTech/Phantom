#include "Ultrasonic.h"

using namespace Phantom;

Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin): trigPin(trigPin), echoPin(echoPin) {
	pinMode(this->trigPin, OUTPUT);
	pinMode(this->echoPin, INPUT);
}

uint16_t Ultrasonic::get(void) {
	// Pulse trigger pin
	Utils::pulse(this->trigPin, this->trigPulseDelta, HIGH);
	// Wait unil signal goes high
	while(!digitalRead(this->echoPin));
	// Remember start time
	uint32_t startTime = micros();
	// Wait while signal is high
	while(digitalRead(this->echoPin));
	// Return calculated value in mm
	return (micros() - startTime) / 5.8f;
}