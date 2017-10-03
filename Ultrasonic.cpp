#include "Ultrasonic.h"

using namespace Phantom;

Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin): trigPin(trigPin), echoPin(echoPin) {
	pinMode(this->trigPin, OUTPUT);
	pinMode(this->echoPin, INPUT);
}

float Ultrasonic::get() {
	pulseHighMicro(trigPin, 10);
	return pulseIn(echoPin, HIGH, timeout) / 5800;
}

void Ultrasonic::setRange(float meters) {
	timeout = meters * 5800;
}