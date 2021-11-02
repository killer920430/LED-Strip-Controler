#include "StripController.hpp"
#include "ColorsTable.hpp"

sk6812<B, 2> StripController::strip{};
bool StripController::needClear{false};
float StripController::brightness = 0.20;
uint8_t StripController::numOfPixels = 33;
uint8_t StripController::currentColor = 0;
Color StripController::color{colors[currentColor]};
rgbw StripController::pixels[maxNumOfPixels] = {};

void StripController::run()
{
    updateColors(Color{color.r * brightness, color.g * brightness, color.b * brightness, color.w * brightness});
    strip.sendPixels(numOfPixels, pixels);
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

void StripController::updateColors(Color color)
{
    for (int i = 0; i < numOfPixels; i++)
    {
        pixels[i].r = color.r;
        pixels[i].g = color.g;
        pixels[i].b = color.b;
        pixels[i].w = color.w;
    }
}