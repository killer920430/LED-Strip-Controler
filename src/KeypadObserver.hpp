#ifndef SRC_KEYPADOBSERVERp
#define SRC_KEYPADOBSERVER
#include <Keypad.h>

class KeypadObserver
{
public:
    void setup();
    void run();
    void registerTrigger(char keyChar, void (*trigger)());

private:
    const uint8_t key1Pin{2};
    const uint8_t key2Pin{3};
    const uint8_t key3Pin{4};
    const uint8_t key4Pin{5};
    bool key1LastState;
    bool key2LastState;
    bool key3LastState;
    bool key4LastState;
    void (*Key1Trigger)(){};
    void (*Key2Trigger)(){};
    void (*Key3Trigger)(){};
    void (*Key4Trigger)(){};
};

#endif /* SRC_KEYPADOBSERVER */
