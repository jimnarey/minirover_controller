/*
  Messenger.h - Messenger library
*/

#include <Arduino.h>
#include "Messenger.h"

Messenger::Messenger()
{

  byte* _encodedCommand = new byte[0];
  termChar = '\n';
  
}

void Messenger::setSerial(Stream *streamObject)
{
  _streamRef = streamObject;
  
}

void Messenger::readFromSerial(void (*)(String message)) 
{
  
}
