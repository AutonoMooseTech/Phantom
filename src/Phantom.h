#ifndef PHANTOM_H
#define PHANTOM_H

	#ifndef ARDUINO_SAM_ZERO
	#include <StandardCplusplus.h>
	#endif

#include <Arduino.h>
#undef min
#undef max
#undef abs

// Digital States
#undef LOW
#undef HIGH
enum {LOW, HIGH};
// Pin Modes
#undef INPUT
#undef OUTPUT
#undef INPUT_PULLUP
enum {INPUT, OUTPUT, INPUT_PULLUP};
// Interrupt Trigger Types
#undef CHANGE
#undef FALLING
#undef RISING
enum {CHANGE = 1, FALLING = 2, RISING = 3};

namespace Phantom {
	// Constants and Defines

	const uint8_t BIT0 = 0x01;	// 00000001
	const uint8_t BIT1 = 0x02;	// 00000010
	const uint8_t BIT2 = 0x04;	// 00000100
	const uint8_t BIT3 = 0x08;	// 00001000
	const uint8_t BIT4 = 0x10;	// 00010000
	const uint8_t BIT5 = 0x20;	// 00100000
	const uint8_t BIT6 = 0x40;	// 01000000
	const uint8_t BIT7 = 0x80;	// 10000000


	// Data structures

	union bytes2 {
		uint16_t u16;
		struct {
			uint8_t b1;
			uint8_t b0;
		};
	};

	union bytes4 {
		uint32_t u32;
		struct {
			uint8_t b3;
			uint8_t b2;
			uint8_t b1;
			uint8_t b0;
		};
	};

	// Inline Functions

	template<typename T, typename T2> inline bool getBit(T data,  T2 n) { return (data &= (1u << n)); } // test nth bit
	template<typename T> inline void setBit(T &data, byte n) { data |= (1u << n); }   // set nth bit
	template<typename T> inline void clearBit(T &data, byte n) { data &= ~(1u << n); }  // clear nth bit
	template<typename T> inline void toggleBit(T &data, byte n) { data ^= (1u << n); }   // toggle nth bit
	template<typename T> inline void changeBit(T &data, byte n, bool x) { data = (-x ^ data) & (1 << n); } // change nth bit

	template<typename T> inline T    getMask(T data,  T m)   { return (data &= m); } // test many bits
	template<typename T> inline void setMask(T &data, T m)   { data |= m; }          // set many bits
	template<typename T> inline void clearMask(T &data, T m)   { data &= ~m; }         // clear many bits
	template<typename T> inline void toggleMask(T &data, T m)   { data ^= m; }          // toggle many bits


	// Map an input value to an output
	// Input and output types can be different
	template<typename T, typename T2, typename T3>
	inline T map(T3 val, T2 in_min, T2 in_max, T out_min, T out_max) {
		return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}

	// Get the difference of two numbers and return as an absolute value
	// x = |(a - b)|
	template<typename T>
	inline T delta(T a, T b) {
		return T(fabs(a - b));
	}

	// Return value within high and low limits
	// #ifndef is needed because Arduino uses a macro for its equivalen
	#ifdef constrain
	#undef constrain
	#endif
	template<typename T, typename T2>
	inline T2 constrain(T x, T2 a, T2 b) {
		if(x < a) {
			return a;
		}
		else if(b < x) {
			return b;
		}
		else
			return x;
	}
}

#endif