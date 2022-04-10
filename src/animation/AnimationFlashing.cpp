#include "AnimationFlashing.hpp"

namespace animation
{
    AnimationFlashing::AnimationFlashing(config::ConfigMgr &configMgr, Strip &stripFront, Strip &stripBack, Strip &stripLeft, Strip &stripRight)
        : AnimationBase(configMgr, stripFront, stripBack, stripLeft, stripRight) {}

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
                setStripColor(stripFront);
                setStripColor(stripBack);
                setStripColor(stripLeft);
                setStripColor(stripRight);
            }
            else
            {
                clearAll();
            }
            showAll();
        }
    }

    void AnimationFlashing::resetAnimation()
    {
    }
}