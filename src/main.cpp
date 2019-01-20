#include <Arduino.h>

/*
    |o  1   RAW   o|
    |o  0   GND   o|
    |o  GND RST   o| 
    |o  GND VCC   o|
    |o  2   21    o|
    |o  3   20    o|
    |o  4   19    o|
    |p  5   18    o|
    |p  6   15    o|
    |o  7   14    o|
    |o  8   16    o|
    |p  9   10    p|

    PWM Pins:
    Arduino 10, Arduino green, Driver blue, steer LEFT
    Arduino 9, Arduino blue, Driver purple, steer RIGHT
    Arduino 6, Arduino purple, Driver yellow, drive REVERSE
    Arduino 5, Arduino grey, Driver orange, drive FORWARD
 */

#define btSerial Serial1
#define usbSerial Serial

// Set pins to direction names
int forward = 5;
int reverse = 6;
int right = 9;
int left = 10;

bool hasRun = false;

void setup() {
  // put your setup code here, to run once:
  usbSerial.begin(9600);
  btSerial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  btSerial.println("BT_Test");
  usbSerial.println("USB_Test");
  delay(1000);

}
