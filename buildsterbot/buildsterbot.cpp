/*
  buildsterbot library
  copyright Christopher Walter James Palmer 2015
*/

#include "Arduino.h"
#include "Buildsterbot.h"

Buildsterbot::Buildsterbot() {
  // run setup functions here - remember to include arguments
  onBoardLED.setup(13);

}

void DigitalInput::setup(int pin, bool stateThatMeansIsOn){
  pinMode(pin, INPUT);
  _pin = pin;
  _stateThatMeansIsOn = stateThatMeansIsOn;
}
bool DigitalInput::isOn(){
  if ( _stateThatMeansIsOn == HIGH) {
    return digitalRead(_pin);
  } else {
    return ! digitalRead(_pin);
  }
}
bool DigitalInput::isOff(){
  return ! isOn();
}

void DigitalOutput::setup(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}
void DigitalOutput::turnOn() {
  digitalWrite(_pin, HIGH);
  _stateIsOn = true;
}
void DigitalOutput::turnOff() {
  digitalWrite(_pin, LOW);
  _stateIsOn = false;
}
bool DigitalOutput::isOn() {
  return _stateIsOn;
}
bool DigitalOutput::isOff() {
  return ! _stateIsOn;
}

void AnalogInput::setup(int pin) {
  pinMode(pin,INPUT);
  _pin = pin;
}
int AnalogInput::reading() {
  return analogRead(_pin);
}

void AnalogOutput::setup(int pin) {
  _pin = pin;
  pinMode(_pin,OUTPUT);
}
void AnalogOutput::set(int newSetting) {
  analogWrite(_pin, newSetting);
  _currentSetting = newSetting;
}
int AnalogOutput::setting() {
  return _currentSetting;
}
