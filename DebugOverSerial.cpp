#include "DebugOverSerial.h"

DebugOverSerial::DebugOverSerial(uint16_t baud) {
	this->baud = baud;
	Serial.begin(this->baud);
}

void DebugOverSerial::enable(void) {
	enabled = true;
}

void DebugOverSerial::disable(void) {
	enabled = false;
}

void DebugOverSerial::print(String input) {
	if (enabled) Serial.print(input);
}

void DebugOverSerial::println(String input) {
	if (enabled) Serial.println(input);
}

void DebugOverSerial::printTitle(String input) {
	Serial.print("["); // Begining

	for (uint8_t i = 0; i < (input.length() / 2) - 2; i++) {
		Serial.print("-");
	}

	Serial.print(" ");
	Serial.print(input); // Print title
	Serial.print(" ");

	for (uint8_t i = 0; i < (input.length() / 2) - 2; i++) {
		Serial.print("-");
	}

	Serial.print("]"); // Ending
}