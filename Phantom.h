#ifndef PHANTOM_H
#define PHANTOM_H

#include <Arduino.h>

namespace Phantom {
	// Type Definitions

	/*#ifndef int8_t
	typedef char                 int8_t;
	typedef short                int16_t;
	typedef long                 int32_t;
	typedef long long            int64_t;
	#endif

	#ifndef uint8_t
	typedef unsigned char        uint8_t;
	typedef unsigned short       uint16_t;
	typedef unsigned long        uint32_t;
	typedef unsigned long long   uint64_t;
	#endif

	#ifndef byte
	typedef unsigned char        byte;
	#endif */

	// Constants and Defines

	const uint8_t BIT0 = 0x01;	// 00000001
	const uint8_t BIT1 = 0x02;	// 00000010
	const uint8_t BIT2 = 0x04;	// 00000100
	const uint8_t BIT3 = 0x08;	// 00001000
	const uint8_t BIT4 = 0x10;	// 00010000
	const uint8_t BIT5 = 0x20;	// 00100000
	const uint8_t BIT6 = 0x40;	// 01000000
	const uint8_t BIT7 = 0x80;	// 10000000

	const uint8_t ON  = true;	// Same as HIGH
	const uint8_t OFF = false;	// Same as LOW
	const uint8_t HI  = true;	// Same as HI
	const uint8_t LO  = false;	// Same as LO


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

	template<typename T> inline bool getBit(T data,  byte n) { return (data &= (1u << n)); } // test nth bit
	template<typename T> inline void setBit(T &data, byte n) { data |= (1u << n); }   // set nth bit
	template<typename T> inline void clrBit(T &data, byte n) { data &= ~(1u << n); }  // clear nth bit
	template<typename T> inline void togBit(T &data, byte n) { data ^= (1u << n); }   // toggle nth bit

	template<typename T> inline T    getMask(T data,  T m)   { return (data &= m); } // test many bits
	template<typename T> inline void setMask(T &data, T m)   { data |= m; }          // set many bits
	template<typename T> inline void clrMask(T &data, T m)   { data &= ~m; }         // clear many bits
	template<typename T> inline void togMask(T &data, T m)   { data ^= m; }          // toggle many bits


	// Map an input value to an output
	// Input and output types can be different
	template<typename T, typename T2>
	inline T map(T2 val, T2 in_min, T2 in_max, T out_min, T out_max) {
		return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
	}

	// Pulse and output HIGH and then return to LOW after given delay
	// Note this function is blocking
	inline void pulseHi(byte pin, uint32_t deltaUs = 0) {
		digitalWrite(pin, HI);
		if(deltaUs) delayMicroseconds(deltaUs);
		digitalWrite(pin, LO);
	}

	// Pulse an output LOW and then return to HIGH after given delay
	// Note this function is blocking
	inline void pulseLo(byte pin, uint32_t deltaUs = 0) {
		digitalWrite(pin, LO);
		if(deltaUs) delayMicroseconds(deltaUs);
		digitalWrite(pin, HI);
	}

	// Get the differentce of two numbers and return as an absolute value
	// x = |(a - b)|
	template<typename T>
	inline T delta(T a, T b) {
		return T(fabs(a - b));
	}

	// Gets the the length of an array
	// Better than sizeof for array lengths
	template <typename T,unsigned S>
	inline unsigned arrayLength(const T (&v)[S]) {
		return S;
	}

	// Return value within high and low limits
	// #ifndef is needed because Arduino uses a macro for its equivalent
	#ifndef constrain
	#define constrain
	template<typename T>
	inline T constrain(T x, T a, T b) {
		if(x < a) {
			return a;
		}
		else if(b < x) {
			return b;
		}
		else
			return x;
	}
	#endif
}

#endif