#include "Strip.hpp"

Strip::Strip(const int &&nrOfLeds, void (*setup)(CRGB *, const int)) : numberOfLeds{nrOfLeds}
{
    leds = new CRGB[numberOfLeds]{};
    setup(leds, numberOfLeds);
    calculateMiddleLed();
}

void Strip::setColor(const CRGB &color, const int &pos)
{
    leds[pos] = color;
}

void Strip::show()
{
    FastLED.show();
}

void Strip::clear()
{
    for (int i = 0; i < numberOfLeds; i++)
        setColor(CRGB::Black, i);
    show();
}

void Strip::calculateMiddleLed()
{
    middleLedIndex = numberOfLeds / 2;
    singleMiddleLed = (numberOfLeds % 2) ? true : false;
}
