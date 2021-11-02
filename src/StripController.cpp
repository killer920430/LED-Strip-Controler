#include "StripController.hpp"
#include "ColorsTable.hpp"

sk6812<B, 2> StripController::strip{};
rgbw StripController::pixels[maxNumOfPixels]{};
float StripController::brightness = 0.20;
int StripController::numOfPixels = 33;
bool StripController::needClear{false};
uint8_t StripController::currentColor = 0;
Color StripController::color{colors[currentColor]};
static StripMode StripController::mode{};
static long int StripController::delay = maxDelay;
static int StripController::middleLed = numOfPixels % 2;
static bool StripController::singleMiddleLed = true;
uint8_t StripController::phase = 0;
uint8_t StripController::ledshift = 0;

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
    case StripMode::fromMiddle:
        fromMiddleMode(Color{color.r * brightness, color.g * brightness, color.b * brightness, color.w * brightness});
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
    resetAnimation();
}

void StripController::decreaseBrightness()
{
    if (brightness > F_EPSILON)
        brightness -= 0.05;
    resetAnimation();
}

void StripController::increaseNummOfPixels()
{
    if (numOfPixels < maxNumOfPixels)
        numOfPixels += 11;
    resetAnimation();
}

void StripController::decreaseNummOfPixels()
{
    if (numOfPixels > 0)
        numOfPixels -= 11;
    needClear = true;
    resetAnimation();
}

static void StripController::decreaseSpeed()
{
    if (delay < maxDelay)
        delay = delay + delaySteep;
    resetAnimation();
}

static void StripController::increaseSpeed()
{
    if (delay > minDelay)
        delay = delay - delaySteep;
    resetAnimation();
}

void StripController::nextColor()
{
    if (currentColor < (numOfColors - 1))
        ++currentColor;
    else
        currentColor = 0;
    color = colors[currentColor];
    resetAnimation();
}

void StripController::previousColor()
{
    if (currentColor > 0)
        --currentColor;
    else
        currentColor = numOfColors - 1;
    color = colors[currentColor];
    resetAnimation();
}

void StripController::changeMode(StripMode m)
{
    mode = m;
    resetAnimation();
}

void StripController::calculateMiddleLed()
{
    middleLed = numOfPixels / 2;
    if (numOfPixels % 2)
        singleMiddleLed = true;
    else
        singleMiddleLed = false;
}

void StripController::resetAnimation()
{
    phase = 0;
    ledshift = 0;
    calculateMiddleLed();
    strip.clear(maxNumOfPixels);
    Color color{0, 0, 0, 0};
    for (int i = 0; i < maxNumOfPixels; i++)
    {
        setPixelColor(i, color);
    }
}

void StripController::setPixelColor(int pos, Color color)
{
    pixels[pos].r = color.r;
    pixels[pos].g = color.g;
    pixels[pos].b = color.b;
    pixels[pos].w = color.w;
}

void StripController::constantMode(Color color)
{
    for (int i = 0; i < numOfPixels; i++)
    {
        setPixelColor(i, color);
    }
    strip.sendPixels(numOfPixels, pixels);
}

void StripController::flashingMode(Color color)
{
    static bool on = false;
    static unsigned long timeNow = 0;
    Color black{0, 0, 0, 0};

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
            setPixelColor(i, color);
        }
    }
    else
    {
        for (int i = 0; i < numOfPixels; i++)
        {
            setPixelColor(i, black);
        }
    }
    strip.sendPixels(numOfPixels, pixels);
}

void StripController::fromMiddleMode(Color color)
{
    static bool continueAnimation = false;
    static unsigned long timeNow = 0;
    Color fadedColor{color.r / 6, color.g / 6, color.b / 6, color.w / 6};

    if (millis() > timeNow + (delay / 10))
    {
        timeNow = millis();
        if (continueAnimation)
            continueAnimation = false;
        else
            continueAnimation = true;
    }

    if (continueAnimation)
    {
        if (phase == 0)
        {
            if (singleMiddleLed)
            {
                setPixelColor(middleLed + ledshift, fadedColor);
                setPixelColor(middleLed - ledshift, fadedColor);
            }
            else
            {
                setPixelColor(middleLed - 1 + ledshift, fadedColor);
                setPixelColor(middleLed - ledshift, fadedColor);
            }
            if (ledshift == middleLed)
            {
                ledshift = 0;
                ++phase;
            }
            else
                ++ledshift;
        }
        if (phase == 1)
        {
            if (singleMiddleLed)
            {
                setPixelColor(middleLed + ledshift, color);
                setPixelColor(middleLed - ledshift, color);
            }
            else
            {
                setPixelColor(middleLed - 1 + ledshift, color);
                setPixelColor(middleLed - ledshift, color);
            }
            if (ledshift == middleLed)
            {
                ledshift = 0;
                ++phase;
            }
            else
                ++ledshift;
        }
        continueAnimation = false;
    }

    strip.sendPixels(numOfPixels, pixels);
}