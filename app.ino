#include "src/KeypadObserver.hpp"
#include "src/StripController.hpp"

KeypadObserver keypadObserver{};
StripController stripController{};

void setup()
{
    stripController.setup();
    keypadObserver.registerTrigger('8', stripController.previousColor);
    keypadObserver.registerTrigger('0', stripController.nextColor);
    keypadObserver.registerTrigger('A', stripController.increaseBrightness);
    keypadObserver.registerTrigger('B', stripController.decreaseBrightness);
    keypadObserver.registerTrigger('C', stripController.increaseNummOfPixels);
    keypadObserver.registerTrigger('D', stripController.decreaseNummOfPixels);
}

void loop()
{
    keypadObserver.run();

    stripController.tryClearLeds();
    stripController.run();
    delay(100);
}
