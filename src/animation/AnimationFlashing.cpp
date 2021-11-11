#include "AnimationFlashing.hpp"

namespace animation
{
    void AnimationFlashing::run()
    {
        if (on)
        {
            static bool ledOn = false;
            static unsigned long timeNow = 0;
            Color black{0, 0, 0, 0};

            if (continueAnimation(timeNow))
            {
                timeNow = millis() + delays[delayIndex];
                if (ledOn)
                    ledOn = false;
                else
                    ledOn = true;
            }

            if (ledOn)
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
    }

    void AnimationFlashing::resetAnimation()
    {
    }
}