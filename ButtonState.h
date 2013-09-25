#ifndef ButtonState_h
#define ButtonState_h

#include "Arduino.h"

class ButtonState
{
  public:
    ButtonState(int pin);
    typedef void (*callback)();
    void observer();
    void whenPressedCall(void (*callback)());
    void whenPressedDigitalSwitch(int pin);
    void whenPressedAnalogWrite(int pin, int value);
    void setHoldDelay(long delay);
  private:
    int _pin;
    int _state;
    int _lastState;
    long _startHold;
    long _holdDelay;
    bool _allow;
    int _dSwitch;
    int _aWritePin;
    int _aWriteValue;
    callback _call;
};

#endif
