#include "AnimationFlashing.hpp"

namespace animation
{
    void AnimationFlashing::run()
    {
        if (on)
        {
            static bool ledOn = false;
            static unsigned long timeNow = 0;

            if (continueAnimation(timeNow))
            {
                timeNow = millis() + delays[delayIndex];
                ledOn = (ledOn) ? false : true;
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
                    setPixelColor(i, colorTurnOff);
                }
            }
            strip.sendPixels(numOfPixels, pixels);
        }
    }

    void AnimationFlashing::resetAnimation()
    {
    }
}