#include "Ultrasonic.h"

using namespace Phantom;

Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin): trigPin(trigPin), echoPin(echoPin) {
	pinMode(this->trigPin, OUTPUT);
	pinMode(this->echoPin, INPUT);
}

float Ultrasonic::get() {
	return aquire();
}

float Ultrasonic::aquire() {
	pulseHiMicro(trigPin, trigPulseDelta);
	distance = pulseIn(echoPin, HIGH, 5000) / 5.8f;
	return distance;
}