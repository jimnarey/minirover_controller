/*
  RPC.h - RPC library
*/

#ifndef RPC_h
#define RPC_h

#include <Arduino.h>

class RPC
{
  private:
    Stream *_streamRef;

  public:
    RPC();
    void setSerial(Stream *streamObject);
};

#endif