/*
  buildsterbot library
  copyright Christopher Walter James Palmer 2015
*/

#include "Arduino.h"
#include "Buildsterbot.h"
#include <Servo.h>

DigitalInput::DigitalInput(int pin, bool stateThatMeansIsOn) {

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
  // _value = 0;
  // // take 5 readings
  // for (int i; i < 5; i++) {
  //   _value = _value + analogRead(_pin);
  //   delay(2);
  // }
  // _value = (float)l_value / (float)l5; // THIS IS THE PROBLEM
  // // return average reading
  // return _value;
    // return analogRead(_pin);
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

void SERVO::setup(int pin) {
  _pin = pin;
  _servo.attach(_pin);
  setPosition(0);
}
void SERVO::setPosition(int position){
  if ( position > 180 ) {
    _positionSetting = 180;
  } else {
    _positionSetting = position;
  }
  _servo.write(_positionSetting);
}
int SERVO::currentPosition(){
  return _positionSetting;
}
