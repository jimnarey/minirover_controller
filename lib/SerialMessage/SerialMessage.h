/*
  SerialMessage.h - SerialMessage library
*/

#ifndef SerialMessage_h
#define SerialMessage_h

#include <Arduino.h>

class SerialMessage
{
  private:
    Stream *_streamRef;

  public:
    SerialMessage();
    void setSerial(Stream *streamObject);
};

#endif