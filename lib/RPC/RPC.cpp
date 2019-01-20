/*
  RPC.h - RPC library
*/

#include <Arduino.h>
#include "RPC.h"

RPC::RPC()
{

}

void RPC::setSerial(Stream *streamObject)
{
  _streamRef = streamObject;
}

