#ifndef SRC_KEYPADOBSERVERp
#define SRC_KEYPADOBSERVER
#include <Keypad.h>

class KeypadObserver
{
public:
    void run();
    void registerTrigger(char keyChar, void (*trigger)());

private:
    static constexpr byte ROWS = 4;
    static constexpr byte COLS = 4;
    const char keys[ROWS][COLS] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}};

    const byte rowPins[ROWS] = {9, 8, 7, 6};
    const byte colPins[COLS] = {5, 4, 3, 2};

    Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

    void (*Key1Trigger)(){};
    void (*Key2Trigger)(){};
    void (*Key3Trigger)(){};
    void (*Key4Trigger)(){};
    void (*Key5Trigger)(){};
    void (*Key6Trigger)(){};
    void (*Key7Trigger)(){};
    void (*Key8Trigger)(){};
    void (*Key9Trigger)(){};
    void (*Key0Trigger)(){};
    void (*KeyATrigger)(){};
    void (*KeyBTrigger)(){};
    void (*KeyCTrigger)(){};
    void (*KeyDTrigger)(){};
    void (*KeyStarTrigger)(){};
    void (*KeyHashTrigger)(){};
};

#endif /* SRC_KEYPADOBSERVER */
