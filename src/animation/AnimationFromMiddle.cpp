#include "AnimationFromMiddle.hpp"

namespace animation
{
    void AnimationFromMiddle::run()
    {
        if (on)
        {
            static bool run = false;
            static unsigned long timeNow = 0;
            Color fadedColor{color.r / 6, color.g / 6, color.b / 6, color.w / 6};

            if (continueAnimation(timeNow))
            {
                timeNow = millis() + delay / 10;
                if (run)
                    run = false;
                else
                    run = true;
            }

            if (run)
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
                run = false;
            }

            strip.sendPixels(numOfPixels, pixels);
        }
    }

    void AnimationFromMiddle::resetAnimation()
    {
        phase = 0;
        ledshift = 0;
    }
}