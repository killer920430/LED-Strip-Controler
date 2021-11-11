#include "KeypadObserver.hpp"

void KeypadObserver::setup()
{
    pinMode(key1Pin, INPUT);
    pinMode(key2Pin, INPUT);
    pinMode(key3Pin, INPUT);
    pinMode(key4Pin, INPUT);

    key1LastState = digitalRead(key1Pin);
    key2LastState = digitalRead(key2Pin);
    key3LastState = digitalRead(key3Pin);
    key4LastState = digitalRead(key4Pin);
}

void KeypadObserver::run()
{
    bool keyState = digitalRead(key1Pin);
    if (keyState != key1LastState)
    {
        Key1Trigger();
        key1LastState = keyState;
    }

    keyState = digitalRead(key2Pin);
    if (keyState != key2LastState)
    {
        Key2Trigger();
        key2LastState = keyState;
    }

    keyState = digitalRead(key3Pin);
    if (keyState != key3LastState)
    {
        Key3Trigger();
        key3LastState = keyState;
    }

    keyState = digitalRead(key4Pin);
    if (keyState != key4LastState)
    {
        Key4Trigger();
        key4LastState = keyState;
    }
}

void KeypadObserver::registerTrigger(char key, void (*trigger)())
{
    switch (key)
    {
    case '1':
        Key1Trigger = trigger;
        break;
    case '2':
        Key2Trigger = trigger;
        break;
    case '3':
        Key3Trigger = trigger;
        break;
    case '4':
        Key4Trigger = trigger;
        break;
    default:
        break;
    }
}