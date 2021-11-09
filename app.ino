#include "src/KeypadObserver.hpp"
#include "src/StripController.hpp"
#include "src/StripMode.hpp"

KeypadObserver keypadObserver{};
StripController stripController{};

void setup()
{
    stripController.setup();
    keypadObserver.registerTrigger('1', []()
                                   { stripController.changeMode(StripMode::constatnt); });
    keypadObserver.registerTrigger('2', []()
                                   { stripController.changeMode(StripMode::flashing); });
    keypadObserver.registerTrigger('3', []()
                                   { stripController.changeMode(StripMode::fromMiddle); });
    keypadObserver.registerTrigger('8', []()
                                   { stripController.previousColor(); });
    keypadObserver.registerTrigger('0', []()
                                   { stripController.nextColor(); });
    keypadObserver.registerTrigger('A', []()
                                   { stripController.increaseBrightness(); });
    keypadObserver.registerTrigger('B', []()
                                   { stripController.decreaseBrightness(); });
    keypadObserver.registerTrigger('C', []()
                                   { stripController.increaseNummOfPixels(); });
    keypadObserver.registerTrigger('D', []()
                                   { stripController.decreaseNummOfPixels(); });
    keypadObserver.registerTrigger('*', []()
                                   { stripController.decreaseSpeed(); });
    keypadObserver.registerTrigger('#', []()
                                   { stripController.increaseSpeed(); });
}

void loop()
{
    keypadObserver.run();

    stripController.tryClearLeds();
    stripController.run();
    delay(100);
}
