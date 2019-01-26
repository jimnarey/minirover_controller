/*
  CmdHandle.h - CmdHandle library
*/

#ifndef CmdHandle_h
#define CmdHandle_h

#include <Arduino.h>

class CmdHandle
{

  public:

    CmdHandle();

    struct commandDef{
      int id;
      String name;
    };
    commandDef* localCommands;
    void addLocalCommand(commandDef command);

};

#endif