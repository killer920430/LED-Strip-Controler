#include "AnimationFromMiddle.hpp"

namespace animation
{
    AnimationFromMiddle::AnimationFromMiddle(config::ConfigMgr &configMgr, Strip &strip) : AnimationBase(configMgr, strip) {}

    void AnimationFromMiddle::run()
    {
        if (on && !animationFinished)
        {
            static bool run = false;
            static unsigned long timeNow = 0;
            CRGB fadedColor{(uint8_t)(color.r / fadedFactor),
                            (uint8_t)(color.g / fadedFactor),
                            (uint8_t)(color.b / fadedFactor)};

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

            strip.show();
        }
    }

    void AnimationFromMiddle::resetAnimation()
    {
        phase = 0;
        ledshift = 0;
        animationFinished = false;
    }

    void AnimationFromMiddle::performPhase(const CRGB &currentColor)
    {
        if (singleMiddleLed)
        {
            setPixelColor(middleLedIndex + ledshift, currentColor);
            setPixelColor(middleLedIndex - ledshift, currentColor);
        }
        else
        {
            setPixelColor(middleLedIndex - 1 + ledshift, currentColor);
            setPixelColor(middleLedIndex - ledshift, currentColor);
        }
        if (ledshift == middleLedIndex)
        {
            ledshift = 0;
            ++phase;
        }
        else
            ++ledshift;
    }
}