/*
  buildsterbot library
  copyright Christopher Walter James Palmer 2015, all rights reserved
*/

#ifndef buildsterbot_h
#define buildsterbot_h

#include "Arduino.h"
#include <Servo.h>

class DigitalInput {
  public:
    DigitalInput(int pin, bool stateThatMeansIsOn);
    void setup(int pin, bool stateThatMeansIsOn);
    bool isOn();
    bool isOff();
  private:
    int _pin;
    int _stateThatMeansIsOn;
};

class DigitalOutput {
  public:
    void setup(int pin);
    void turnOn();
    void turnOff();
    bool isOn();
    bool isOff();
  private:
    int _pin;
    int _stateIsOn;
};

class AnalogInput {
  public:
    void setup(int pin);
    int reading();
  private:
    int _pin;
    int _value;
};

class AnalogOutput {
  public:
    void setup(int pin);
    void set(int newSetting);
    int setting();
  private:
    int _pin;
    int _currentSetting;
};

class SERVO {
  public:
    void setup(int pin);
    void setPosition(int position);
    int currentPosition();
  private:
    int _positionSetting;
    int _pin;
    Servo _servo;
};

#endif
