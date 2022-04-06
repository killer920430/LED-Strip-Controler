#include "AnimationStatic.hpp"

namespace animation
{
    AnimationStatic::AnimationStatic(config::ConfigMgr &configMgr) : AnimationBase(configMgr) {}

    void AnimationStatic::run()
    {
        if (on && not animationFinished)
        {
            for (int i = 0; i < numOfPixels; i++)
            {
                setPixelColor(i, color);
            }
            strip.sendPixels(numOfPixels, pixels);
            animationFinished = true;
        }
    }

    void AnimationStatic::resetAnimation()
    {
        animationFinished = false;
    }
}