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
    const uint8_t keyAPin{3};
    const uint8_t keyBPin{5};
    const uint8_t keyCPin{2};
    const uint8_t keyDPin{4};
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
