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
    }
  } 
  _lastState = _state;
  
}

void ButtonState::whenPressedCall(void (*callType)())
{
  _call = &(*callType);
}

void ButtonState::whenPressedDigitalSwitch(int pin)
{
  _dSwitch = pin;
}  

void ButtonState::setHoldDelay(long delay)
{
  _holdDelay = delay;
} 