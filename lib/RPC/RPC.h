/*
  RPC.h - RPC library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef RPC_h
#define RPC_h

// include types & constants of Wiring core API
// #include "WConstants.h"
#include <Arduino.h>

// library interface description
class RPC
{
  // user-accessible "public" interface
  public:
    RPC(int);
    int value;
    void doSomething(void);
};

#endif