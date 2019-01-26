/*
  Messenger.h - Messenger library
*/

#ifndef Messenger_h
#define Messenger_h

#include <Arduino.h>

class Messenger
{
  private:
    Stream* _streamRef;
    char termChar;
    String inCmd;

  public:
    Messenger();
    void setSerial(Stream *streamObject);
    void readFromSerial(void (*)(String message));

};

#endif