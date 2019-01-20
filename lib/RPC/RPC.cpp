/*
  RPC.h - RPC library for Wiring - implementation
  Copyright (c) 2006 John Doe.  All right reserved.
*/


#include <Arduino.h>
// include this library's description file
#include "RPC.h"



// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

RPC::RPC()
{
  // initialize this instance's variables
  // comSerial = refSerial;
  // comSerial* = refSerial*;

  // do whatever is required to initialize the library
//   pinMode(13, OUTPUT);
//   Serial.begin(9600);
}

// Public Methods //////////////////////////////////////////////////////////////
// Functions available in Wiring sketches, this library, and other libraries

void RPC::setSerial(Stream *streamObject)
{
  // eventhough this function is public, it can access
  // and modify this library's private variables
  _streamRef = streamObject;
}

