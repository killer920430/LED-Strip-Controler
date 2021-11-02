#include "StripController.hpp"
#include "ColorsTable.hpp"

sk6812<B, 2> StripController::strip{};
rgbw StripController::pixels[maxNumOfPixels]{};
float StripController::brightness = 0.20;
uint8_t StripController::numOfPixels = 33;
bool StripController::needClear{false};
uint8_t StripController::currentColor = 0;
Color StripController::color{colors[currentColor]};
static StripMode StripController::mode{};
static long int StripController::delay = maxDelay;

void StripController::run()
{
    switch (mode)
    {
    case StripMode::constatnt:
        constantMode(Color{color.r * brightness, color.g * brightness, color.b * brightness, color.w * brightness});
        break;
    case StripMode::flashing:
        flashingMode(Color{color.r * brightness, color.g * brightness, color.b * brightness, color.w * brightness});
        break;
    default:
        break;
    }
}

void StripController::setup()
{
    strip.clear(maxNumOfPixels);
}

void StripController::tryClearLeds()
{
    if (needClear)
    {
        strip.clear(maxNumOfPixels);
        needClear = false;
    }
}

void StripController::increaseBrightness()
{
    if (brightness + F_EPSILON < 1.0)
        brightness += 0.05;
}

void StripController::decreaseBrightness()
{
    if (brightness > F_EPSILON)
        brightness -= 0.05;
}

void StripController::increaseNummOfPixels()
{
    if (numOfPixels < maxNumOfPixels)
        numOfPixels += 11;
}

void StripController::decreaseNummOfPixels()
{
    if (numOfPixels > 0)
        numOfPixels -= 11;
    needClear = true;
}

static void StripController::decreaseSpeed()
{
    if (delay < maxDelay)
        delay = delay + delaySteep;
}

static void StripController::increaseSpeed()
{
    if (delay > minDelay)
        delay = delay - delaySteep;
}

void StripController::nextColor()
{
    if (currentColor < (numOfColors - 1))
        ++currentColor;
    else
        currentColor = 0;
    color = colors[currentColor];
}

void StripController::previousColor()
{
    if (currentColor > 0)
        --currentColor;
    else
        currentColor = numOfColors - 1;
    color = colors[currentColor];
}

void StripController::changeMode(StripMode m)
{
    mode = m;
}

void StripController::constantMode(Color color)
{
    for (int i = 0; i < numOfPixels; i++)
    {
        pixels[i].r = color.r;
        pixels[i].g = color.g;
        pixels[i].b = color.b;
        pixels[i].w = color.w;
    }
    strip.sendPixels(numOfPixels, pixels);
}

void StripController::flashingMode(Color color)
{
    static bool on = false;
    static unsigned long timeNow = 0;

    if (millis() > timeNow + delay)
    {
        timeNow = millis();
        if (on)
            on = false;
        else
            on = true;
    }

    if (on)
    {
        for (int i = 0; i < numOfPixels; i++)
        {
            pixels[i].r = color.r;
            pixels[i].g = color.g;
            pixels[i].b = color.b;
            pixels[i].w = color.w;
        }
    }
    else
    {
        for (int i = 0; i < numOfPixels; i++)
        {
            pixels[i].r = 0;
            pixels[i].g = 0;
            pixels[i].b = 0;
            pixels[i].w = 0;
        }
    }
    strip.sendPixels(numOfPixels, pixels);
}