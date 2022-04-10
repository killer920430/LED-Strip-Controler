#include "AnimationFlashing.hpp"

namespace animation
{
    AnimationFlashing::AnimationFlashing(config::ConfigMgr &configMgr, Strip &strip) : AnimationBase(configMgr, strip) {}

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
                for (int i = 0; i < strip.numberOfLeds; i++)
                {
                    setPixelColor(i, color);
                }
            }
            else
            {
                strip.clear();
            }
            strip.show();
        }
    }

    void AnimationFlashing::resetAnimation()
    {
    }
}