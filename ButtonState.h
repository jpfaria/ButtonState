#ifndef ButtonState_h
#define ButtonState_h

#include "Arduino.h"

class ButtonState
{
  public:
    ButtonState(int pin);
    void observer();
  private:
    int _pin;
    int _state;
    int _lastState;
    long _startHold;
    boolean _allow;
};

#endif