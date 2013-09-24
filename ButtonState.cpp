#include "Arduino.h"
#include "ButtonState.h"

ButtonState::ButtonState(int pin)
{
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  _state = HIGH;
  _lastState = HIGH;
  _startHold = 0;
  _allow = false;
}

void ButtonState::observer()
{
  _state = digitalRead(_pin);

  if (_state == LOW && _lastState == HIGH){  
    _startHold = millis();                       
    _allow = true;                                
  }

  if (_allow == true && _state == LOW && _lastState == LOW){
    if ((millis() - _startHold) >= 20){
      Serial.println(_pin);
      //rlyState = !rlyState;
      _allow = false;
    }
  } 

  _lastState = _state;
  
}