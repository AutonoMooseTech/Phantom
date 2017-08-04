#ifndef PHANTOM_H
#define PHANTOM_H

#include <Arduino.h>

// Classes
#include "DebugOverSerial.h"
#include "I2CSlavePortControl.h"
#include "MotorControler.h"
#include "Relay.h"
#include "SenseLight.h"
#include "SolenoidController.h"
#include "SpeedController.h"
#include "TimerBase.h"
#include "Ultrasonic.h"
#include "VNH2SP30.h"

namespace Phantom {
	// Type Definitions

	#ifndef int8_t
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
	#endif

	// Constants and Defines

	const uint8_t BIT0 = 0x01;
	const uint8_t BIT1 = 0x02;
	const uint8_t BIT2 = 0x04;
	const uint8_t BIT3 = 0x08;
	const uint8_t BIT4 = 0x10;
	const uint8_t BIT5 = 0x20;
	const uint8_t BIT6 = 0x40;
	const uint8_t BIT7 = 0x80;

	const uint8_t ON  = true;
	const uint8_t OFF = false;
	const uint8_t HI  = true;
	const uint8_t LO  = false;


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


	template<typename T, typename T2>
	inline T map(T2 val, T2 in_min, T2 in_max, T out_min, T out_max) {
		return T(val - in_min) * (out_max - out_min) / T(in_max - in_min) + out_min;
	}

	inline void pulseHi(byte pin, uint32_t deltaUs = 0) {
		digitalWrite(pin, HI);
		if(deltaUs) delayMicroseconds(deltaUs);
		digitalWrite(pin, LO);
	}

	inline void pulseLo(byte pin, uint32_t deltaUs = 0) {
		digitalWrite(pin, LO);
		if(deltaUs) delayMicroseconds(deltaUs);
		digitalWrite(pin, HI);
	}

	template<typename T>
	inline T delta(T a, T b) {
		return T(fabs(a - b));
	}

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