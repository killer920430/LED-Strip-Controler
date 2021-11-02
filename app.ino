#include <FAB_LED.h>
#include <Keypad.h>

#include "src/Color.hpp"
#include "src/ColorsTable.hpp"
#include "src/KeypadObserver.hpp"

#define F_EPSILON 0.00001

sk6812<B, 2> strip; //Digital Pin 10

const uint8_t maxNumOfPixels = 176;
rgbw pixels[maxNumOfPixels] = {};
float brightness = 0.20;
uint8_t numOfPixels = 33;
bool needClear = false;
uint8_t currentColor = 0;

Color color{colors[currentColor]};
KeypadObserver keypadObserver;

void setup()
{
    strip.clear(maxNumOfPixels);
    keypadObserver.registerTrigger('8', previousColor);
    keypadObserver.registerTrigger('0', nextColor);
    keypadObserver.registerTrigger('A', increaseBrightness);
    keypadObserver.registerTrigger('B', decreaseBrightness);
    keypadObserver.registerTrigger('C', increaseNummOfPixels);
    keypadObserver.registerTrigger('D', decreaseNummOfPixels);
}

void loop()
{
    keypadObserver.run();

    tryClearLeds();
    updateColors(Color{color.r * brightness, color.g * brightness, color.b * brightness, color.w * brightness});
    strip.sendPixels(numOfPixels, pixels);
    delay(100);
}

void tryClearLeds()
{
    if (needClear)
    {
        strip.clear(maxNumOfPixels);
        needClear = false;
    }
}

void increaseBrightness()
{
    if (brightness + F_EPSILON < 1.0)
        brightness += 0.05;
}

void decreaseBrightness()
{
    if (brightness > F_EPSILON)
        brightness -= 0.05;
}

void increaseNummOfPixels()
{
    if (numOfPixels < maxNumOfPixels)
        numOfPixels += 11;
}

void decreaseNummOfPixels()
{
    if (numOfPixels > 0)
        numOfPixels -= 11;
    needClear = true;
}

void nextColor()
{
    if (currentColor < (numOfColors - 1))
        ++currentColor;
    else
        currentColor = 0;
    color = colors[currentColor];
}

void previousColor()
{
    if (currentColor > 0)
        --currentColor;
    else
        currentColor = numOfColors - 1;
    color = colors[currentColor];
}

void updateColors(Color color)
{
    for (int i = 0; i < numOfPixels; i++)
    {
        pixels[i].r = color.r;
        pixels[i].g = color.g;
        pixels[i].b = color.b;
        pixels[i].w = color.w;
    }
}
