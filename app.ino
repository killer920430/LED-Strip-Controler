#include "src/Controller.hpp"
#include "src/KeypadObserver.hpp"

KeypadObserver keypadObserver{};
Controller controller;

void setup()
{
    keypadObserver.setup();
    keypadObserver.registerTrigger('1', []()
                                   { controller.toogleOnOff(); }); // Remote key C
    keypadObserver.registerTrigger('2', []()
                                   { controller.changeColor(); }); // Remote key A
    keypadObserver.registerTrigger('3', []()
                                   { controller.changeAnimation(); }); // Remote key D
    keypadObserver.registerTrigger('4', []()
                                   { controller.changeSpeed(); }); // Remote key B
}

void loop()
{
    keypadObserver.run();
    controller.run();

    delay(1);
}
