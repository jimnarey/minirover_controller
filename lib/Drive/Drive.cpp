/*
  Drive.h - Drive library
*/

#include <Arduino.h>
#include "Drive.h"

Drive::Drive(int givenValue)
{
  value = givenValue;
}

void Drive::doSomething(void)
{
  Serial.print("value is ");
  Serial.println(value);

}

