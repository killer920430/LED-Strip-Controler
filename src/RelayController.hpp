#ifndef SRC_RELAYCONTROLLER
#define SRC_RELAYCONTROLLER

class RelayController
{
public:
    void setup();
    void on();
    void off();

private:
    const int relay_pin = 8;
};

#endif /* SRC_RELAYCONTROLLER */
