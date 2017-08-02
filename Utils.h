/********************************************************************************
file: utils.h
name: simon hogwood (modified by Liam Kinne)
date: 16 Aug 2016
vers: 1.3.0
---------------------------------------------------------------------------------
desc: basic utilities for Arduino programming

*********************************************************************************/
#ifndef DT_UTILS_H
#define DT_UTILS_H

namespace Utils
{

#include <Arduino.h>
#include "TimerBase.h"

/*===============================================================================
  type defs
--------------------------------------------------------------------------------*/

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


/*===============================================================================
  defines & constants
--------------------------------------------------------------------------------*/

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


/*===============================================================================
  data structures
--------------------------------------------------------------------------------*/

union bytes2
  {
  uint16_t u16;
  struct
    {
    uint8_t b1;
    uint8_t b0;
    };
  };

union bytes4
  {
  uint32_t u32;
  struct
    {
    uint8_t b3;
    uint8_t b2;
    uint8_t b1;
    uint8_t b0;
    };
  };


/*================================================================================
  inline functions
--------------------------------------------------------------------------------*/

template<typename T> inline bool getBit(T data,  byte n) { return (data &= (1u << n)); } // test nth bit
template<typename T> inline void setBit(T &data, byte n) { data |= (1u << n); }   // set nth bit
template<typename T> inline void clrBit(T &data, byte n) { data &= ~(1u << n); }  // clear nth bit
template<typename T> inline void togBit(T &data, byte n) { data ^= (1u << n); }   // toggle nth bit

template<typename T> inline T    getMask(T data,  T m)   { return (data &= m); } // test many bits
template<typename T> inline void setMask(T &data, T m)   { data |= m; }          // set many bits
template<typename T> inline void clrMask(T &data, T m)   { data &= ~m; }         // clear many bits
template<typename T> inline void togMask(T &data, T m)   { data ^= m; }          // toggle many bits


template<typename T>
inline T mapVal(T val, T in_min, T in_max, T out_min, T out_max)
  {
  return (val - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }


inline void pulseHi(byte pin, uint32_t deltaUs = 0)
  {
  digitalWrite(pin, HI);
  if(deltaUs) delayMicroseconds(deltaUs);
  digitalWrite(pin, LO);
  }

inline void pulseLo(byte pin, uint32_t deltaUs = 0)
  {
  digitalWrite(pin, LO);
  if(deltaUs) delayMicroseconds(deltaUs);
  digitalWrite(pin, HI);
  }

template<typename T>
inline T delta(T a, T b) {
	return T(fabs(a - b));
}


/*===============================================================================
  class HeartBeat
--------------------------------------------------------------------------------*/

class HeartBeat: public Phantom::TimerBase
{
private:
  uint8_t ledPin;
  uint8_t ledState;

public:
  HeartBeat(uint8_t pin = 13, uint32_t interval = 500)
    : TimerBase(interval),
      ledPin(pin), ledState(false)
    {
    pinMode(pin, OUTPUT);
    }


  void doWork(void)
    {
    digitalWrite(ledPin, ledState);
    ledState = !ledState;
    }

};// end class HeartBeat


//-------------------------------------------------------------------------------
};     // close namespace utils
#endif // DT_UTILS_H

