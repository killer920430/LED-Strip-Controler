#include "KeypadObserver.hpp"

void KeypadObserver::setup()
{
    pinMode(keyAPin, INPUT);
    pinMode(keyBPin, INPUT);
    pinMode(keyCPin, INPUT);
    pinMode(keyDPin, INPUT);

    keyALastState = digitalRead(keyAPin);
    keyBLastState = digitalRead(keyBPin);
    keyCLastState = digitalRead(keyCPin);
    keyDLastState = digitalRead(keyDPin);
}

void KeypadObserver::run()
{
    bool keyState = digitalRead(keyAPin);
    if (keyState != keyALastState)
    {
        KeyATrigger();
        keyALastState = keyState;
    }

    keyState = digitalRead(keyBPin);
    if (keyState != keyBLastState)
    {
        KeyBTrigger();
        keyBLastState = keyState;
    }

    keyState = digitalRead(keyCPin);
    if (keyState != keyCLastState)
    {
        KeyCTrigger();
        keyCLastState = keyState;
    }

    keyState = digitalRead(keyDPin);
    if (keyState != keyDLastState)
    {
        KeyDTrigger();
        keyDLastState = keyState;
    }
}

void KeypadObserver::registerTrigger(const char key, void (*trigger)())
{
    switch (key)
    {
    case 'A':
        KeyATrigger = trigger;
        break;
    case 'B':
        KeyBTrigger = trigger;
        break;
    case 'C':
        KeyCTrigger = trigger;
        break;
    case 'D':
        KeyDTrigger = trigger;
        break;
    default:
        break;
    }
}