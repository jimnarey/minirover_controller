/*
  Drive.h - Drive library
*/

#ifndef Drive_h
#define Drive_h

#include <Arduino.h>

class Drive
{
  public:
    Drive(int);
    int value;
    void doSomething(void);
};

#endif