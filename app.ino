#include "src/Controller.hpp"
#include "src/KeypadObserver.hpp"

KeypadObserver keypadObserver{};
Controller controller;

void setup()
{
    keypadObserver.setup();
    keypadObserver.registerTrigger('A', []()
                                   { controller.changeColor(); });
    keypadObserver.registerTrigger('B', []()
                                   { controller.changeSpeed(); });
    keypadObserver.registerTrigger('C', []()
                                   { controller.toogleOnOff(); });
    keypadObserver.registerTrigger('D', []()
                                   { controller.changeAnimation(); });
}

void loop()
{
    keypadObserver.run();
    controller.run();

    delay(1);
}
