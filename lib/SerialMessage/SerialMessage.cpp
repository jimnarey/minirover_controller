/*
  SerialMessage.h - SerialMessage library
*/

#include <Arduino.h>
#include "SerialMessage.h"

SerialMessage::SerialMessage()
{

}

void SerialMessage::setSerial(Stream *streamObject)
{
  _streamRef = streamObject;
}

