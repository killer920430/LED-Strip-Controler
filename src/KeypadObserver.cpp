#include "KeypadObserver.hpp"

void KeypadObserver::run()
{
    char key = keypad.getKey();
    if (key)
    {
        switch (key)
        {
        case '1':
            Key1Trigger();
            break;
        case '2':
            Key2Trigger();
            break;
        case '3':
            Key3Trigger();
            break;
        case '4':
            Key4Trigger();
            break;
        case '5':
            Key5Trigger();
            break;
        case '6':
            Key6Trigger();
            break;
        case '7':
            Key7Trigger();
            break;
        case '8':
            Key8Trigger();
            break;
        case '9':
            Key9Trigger();
            break;
        case '0':
            Key0Trigger();
            break;
        case 'A':
            KeyATrigger();
            break;
        case 'B':
            KeyBTrigger();
            break;
        case 'C':
            KeyCTrigger();
            break;
        case 'D':
            KeyDTrigger();
            break;
        case '*':
            KeyStarTrigger();
            break;
        case '#':
            KeyHashTrigger();
            break;
        default:
            break;
        }
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
    case '5':
        Key5Trigger = trigger;
        break;
    case '6':
        Key6Trigger = trigger;
        break;
    case '7':
        Key7Trigger = trigger;
        break;
    case '8':
        Key8Trigger = trigger;
        break;
    case '9':
        Key9Trigger = trigger;
        break;
    case '0':
        Key0Trigger = trigger;
        break;
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
    case '*':
        KeyStarTrigger = trigger;
        break;
    case '#':
        KeyHashTrigger = trigger;
        break;
    default:
        break;
    }
}