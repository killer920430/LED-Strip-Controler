#include "Strip.hpp"

Strip::Strip(const int &&nrOfLeds) : numberOfLeds{nrOfLeds}
{
    leds = new CRGB[numberOfLeds];
    FastLED.addLeds<NEOPIXEL, 10>(leds, numberOfLeds);
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
