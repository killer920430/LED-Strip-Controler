#include "src/Controller.hpp"
#include "src/KeypadObserver.hpp"
#include "src/RelayController.hpp"

KeypadObserver keypadObserver{};
RelayController relayController{};
Controller controller{relayController};

void setup()
{
    relayController.setup();
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
