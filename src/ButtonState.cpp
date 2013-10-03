#include "Arduino.h"
#include "ButtonState.h"

ButtonState::ButtonState(int pin)
{
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  _state = HIGH;
  _lastState = HIGH;
  _startHold = 0;
  _holdDelay = 20;
  _allow = false;
  _dSwitch = -1;
  _aWritePin = -1;
  _aWriteValue = -1;
}

void ButtonState::observer() 
{
  _state = digitalRead(_pin);

  if (_state == LOW && _lastState == HIGH){  
    _startHold = millis();                       
    _allow = true;                                
  }

  if (_allow == true && _state == LOW && _lastState == LOW){
    if ((millis() - _startHold) >= _holdDelay){
      Serial.println(_pin);
      _allow = false;
      if (_dSwitch>-1) {
        digitalWrite(_dSwitch, !digitalRead(_dSwitch));
      }
      if (_call) {
        _call();
      }
      if (_aWritePin>-1 && _aWriteValue>-1) {
        analogWrite(_aWritePin, _aWriteValue);
      }
    }
  } 

  _lastState = _state;
}

void ButtonState::call(void (*callback)())
{
  _call = &(*callback);
}

void ButtonState::digitalSwitch(int pin)
{
  _dSwitch = pin;
}

void ButtonState::analogWrite(int pin, int value)
{
  _aWritePin = pin;
  _aWriteValue = value;
}

void ButtonState::holdDelay(long delay)
{
  _holdDelay = delay;
} 
