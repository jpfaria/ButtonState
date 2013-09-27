#ifndef ButtonState_h
#define ButtonState_h

#include "Arduino.h"

class ButtonState
{
  public:
    ButtonState(int pin);
    typedef void (*callback)();
    void observer();
    void call(void (*callback)());
    void digitalSwitch(int pin);
    void analogWrite(int pin, int value);
    void holdDelay(long delay);
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
