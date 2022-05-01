#ifndef SRC_KEYPADOBSERVERp
#define SRC_KEYPADOBSERVER
#include "PinConfiguration.hpp"
#include <Keypad.h>

class KeypadObserver
{
public:
    void setup();
    void run();
    void registerTrigger(const char keyChar, void (*trigger)());

private:
    const uint8_t keyAPin{KEYPAD_2_PIN};
    const uint8_t keyBPin{KEYPAD_4_PIN};
    const uint8_t keyCPin{KEYPAD_1_PIN};
    const uint8_t keyDPin{KEYPAD_3_PIN};
    bool keyALastState;
    bool keyBLastState;
    bool keyCLastState;
    bool keyDLastState;
    void (*KeyATrigger)(){};
    void (*KeyBTrigger)(){};
    void (*KeyCTrigger)(){};
    void (*KeyDTrigger)(){};
};

#endif /* SRC_KEYPADOBSERVER */
