#include "src/Controller.hpp"
#include "src/KeypadObserver.hpp"

KeypadObserver keypadObserver{};
Controller controller;

void setup()
{
    keypadObserver.setup();
    keypadObserver.registerTrigger('1', []()
                                   { controller.toogleOnOff(); });
    keypadObserver.registerTrigger('2', []()
                                   { controller.changeColor(); });
    keypadObserver.registerTrigger('3', []()
                                   { controller.changeAnimation(); });
    keypadObserver.registerTrigger('4', []()
                                   { controller.changeSpeed(); });
}

void loop()
{
    keypadObserver.run();
    controller.run();

    delay(1);
}
