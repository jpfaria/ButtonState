#ifndef ButtonState_h
#define ButtonState_h

#include "Arduino.h"

class ButtonState
{
  public:
    ButtonState(int pin);
    typedef void (*callType)();
    void observer();
    void whenPressedCall(void (*callType)());
    void whenPressedDigitalSwitch(int pin);
  private:
    int _pin;
    int _state;
    int _lastState;
    long _startHold;
    bool _allow;
    int _dSwitch;
    callType _call;
};

#endif