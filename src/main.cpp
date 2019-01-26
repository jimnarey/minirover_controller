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

#define usbSerial Serial
#define btSerial Serial1
#define btSerialEvent SerialEvent1

// Set pins to direction names
int forward = 5;
int reverse = 6;
int right = 9;
int left = 10;
float maxMotorSpeed = 0.75;
char inCmd[64];
// String inCmd;
const char* termChar = "\n";

struct motor {
  int pin0;
  int pin1;
} driveMotor, steerMotor;

// bool cmdComplete = false;

void brakeMotor(motor activeMotor) {
  btSerial.println("Run brakeMotor");
  analogWrite(activeMotor.pin0, 127);
  analogWrite(activeMotor.pin1, 127);
}

void motorOff(motor activeMotor) {
  btSerial.println("Run motorOff");
  digitalWrite(activeMotor.pin0, LOW);
  digitalWrite(activeMotor.pin1, LOW);
}

unsigned char percSpeedToByte(int percSpeed) {
  return (percSpeed / 100) * 255 * maxMotorSpeed;
}

void setMotor(motor activeMotor, bool defaultDirection, int percSpeed) 
{ 
  btSerial.println("Run setMotor");
  int byteSpeed = percSpeedToByte(percSpeed);
  if (defaultDirection == true) {
    digitalWrite(activeMotor.pin1, LOW);
    analogWrite(activeMotor.pin0, percSpeed);
  } else {
    digitalWrite(activeMotor.pin0, LOW);
    analogWrite(activeMotor.pin1, percSpeed);
  }
}

void runCmd(char * inst, char * val)
{
  btSerial.println("Run cmd:");
  btSerial.println(inst);
  btSerial.println(val);
  if (inst == "FWD") {
    btSerial.println("Case FWD");
    int percSpeed = atoi(val);
    setMotor(driveMotor, true, percSpeed);
  } else if (inst == "REV") {
    btSerial.println("Case REV");
    int percSpeed = atoi(val);
    setMotor(driveMotor, false, percSpeed);
  } else if (inst == "NTL") {
    btSerial.println("Case NTL");
    motorOff(driveMotor);
  } else if (inst == "BRK") {
    btSerial.println("Case BRK");
    brakeMotor(driveMotor);
  }
}

// Need to change val to numerical type
void parseCmd(char cmd[]) {
  char * inst;
  char * val;
  inst = strtok (cmd,":");
  val = strtok (NULL,":");
  btSerial.println("Parse Cmd:");
  btSerial.println(inst);
  btSerial.println(val);
  btSerial.println("--------");
  runCmd(inst, val);
}

void processCmd() {
  if (btSerial.available()) {
    btSerial.readBytes(inCmd, 64);
    parseCmd(inCmd);
    // btSerial.println(inCmd);
  }
}

void setup() {
  
  // inCmd.reserve(64);
  driveMotor.pin0 = 5;
  driveMotor.pin1 = 6;
  steerMotor.pin0 = 9;
  steerMotor.pin1 = 10;

  usbSerial.begin(9600);
  btSerial.begin(9600);

}

void loop() {
  // btSerial.println("Hello\n");
  // delay(1000);
  processCmd();
  
}










