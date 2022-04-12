#include "RelayController.hpp"

#include "Arduino.h"

void RelayController::setup()
{
    pinMode(relay_pin, OUTPUT);
    off();
}

void RelayController::on()
{
    digitalWrite(relay_pin, LOW);
}

void RelayController::off()
{
    digitalWrite(relay_pin, HIGH);
}