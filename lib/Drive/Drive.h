/*
  Drive.h - Drive library for Wiring - description
  Copyright (c) 2006 John Doe.  All right reserved.
*/

// ensure this library description is only included once
#ifndef Drive_h
#define Drive_h

// include types & constants of Wiring core API
// #include "WConstants.h"
#include <Arduino.h>

// library interface description
class Drive
{
  // user-accessible "public" interface
  public:
    Drive(int);
    int value;
    void doSomething(void);
};

#endif