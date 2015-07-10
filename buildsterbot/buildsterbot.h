/*
  buildsterbot library
  copyright Christopher Walter James Palmer 2015
*/

#ifndef buildsterbot_h
#define buildsterbot_h

#include "Arduino.h"

class DigitalInput {
  public:
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

#endif
