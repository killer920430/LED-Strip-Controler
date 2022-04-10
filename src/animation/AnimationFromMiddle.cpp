#include "AnimationFromMiddle.hpp"

namespace animation
{
    AnimationFromMiddle::AnimationFromMiddle(config::ConfigMgr &configMgr, Strip &stripFront, Strip &stripBack, Strip &stripLeft, Strip &stripRight)
        : AnimationBase(configMgr, stripFront, stripBack, stripLeft, stripRight) {}

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
                    performPhase(fadedColor, stripFront); // add suport for multiple strips
                }
                else if (phase == 1)
                {
                    performPhase(color, stripFront); // add suport for multiple strips
                }
                else
                {
                    animationFinished = true;
                }
                run = false;
            }

            stripFront.show(); // add suport for multiple strips
        }
    }

    void AnimationFromMiddle::resetAnimation()
    {
        phase = 0;
        ledshift = 0;
        animationFinished = false;
    }

    void AnimationFromMiddle::performPhase(const CRGB &currentColor, Strip &strip)
    {
        if (strip.singleMiddleLed)
        {
            setPixelColor(strip.middleLedIndex + ledshift, currentColor, strip);
            setPixelColor(strip.middleLedIndex - ledshift, currentColor, strip);
        }
        else
        {
            setPixelColor(strip.middleLedIndex - 1 + ledshift, currentColor, strip);
            setPixelColor(strip.middleLedIndex - ledshift, currentColor, strip);
        }
        if (ledshift == strip.middleLedIndex)
        {
            ledshift = 0;
            ++phase;
        }
        else
            ++ledshift;
    }
}