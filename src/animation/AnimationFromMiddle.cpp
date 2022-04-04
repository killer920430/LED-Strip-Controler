#include "AnimationFromMiddle.hpp"

namespace animation
{
    void AnimationFromMiddle::run()
    {
        if (on && !animationFinished)
        {
            static bool run = false;
            static unsigned long timeNow = 0;
            Color fadedColor{(uint8_t)(color.r / fadedFactor),
                             (uint8_t)(color.g / fadedFactor),
                             (uint8_t)(color.b / fadedFactor),
                             (uint8_t)(color.w / fadedFactor)};

            if (continueAnimation(timeNow))
            {
                timeNow = millis() + delays[delayIndex] / 10;
                run = (run) ? false : true;
            }

            if (run)
            {
                if (phase == 0)
                {
                    performPhase(fadedColor);
                }
                else if (phase == 1)
                {
                    performPhase(color);
                }
                else
                {
                    animationFinished = true;
                }
                run = false;
            }

            strip.sendPixels(numOfPixels, pixels);
        }
    }

    void AnimationFromMiddle::resetAnimation()
    {
        phase = 0;
        ledshift = 0;
        animationFinished = false;
    }

    void AnimationFromMiddle::performPhase(const Color &currentColor)
    {
        if (singleMiddleLed)
        {
            setPixelColor(middleLed + ledshift, currentColor);
            setPixelColor(middleLed - ledshift, currentColor);
        }
        else
        {
            setPixelColor(middleLed - 1 + ledshift, currentColor);
            setPixelColor(middleLed - ledshift, currentColor);
        }
        if (ledshift == middleLed)
        {
            ledshift = 0;
            ++phase;
        }
        else
            ++ledshift;
    }
}