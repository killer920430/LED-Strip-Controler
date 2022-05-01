#ifndef SRC_RELAYCONTROLLER
#define SRC_RELAYCONTROLLER
#include "PinConfiguration.hpp"

class RelayController
{
public:
    void setup();
    void on();
    void off();

private:
    const int relay_pin = RELAY_PIN;
};

#endif /* SRC_RELAYCONTROLLER */
