/*
  SerialMessage.h - SerialMessage library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef SerialMessage_h
#define SerialMessage_h

// include types & constants of Wiring core API
// #include "WConstants.h"
#include <Arduino.h>
// #include <HardwareSerial.h>
// #include <HardwareSerial.h>

// library interface description
class SerialMessage
{
  private:
    Stream *_streamRef;

  public:
    SerialMessage();
    void setSerial(Stream *streamObject);
};

#endif