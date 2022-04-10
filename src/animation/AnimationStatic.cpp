#include "AnimationStatic.hpp"

namespace animation
{
    AnimationStatic::AnimationStatic(config::ConfigMgr &configMgr, Strip &strip) : AnimationBase(configMgr, strip) {}

    void AnimationStatic::run()
    {
        if (on && not animationFinished)
        {
            for (int i = 0; i < strip.numberOfLeds; i++)
            {
                setPixelColor(i, color);
            }
            strip.show();
            animationFinished = true;
        }
    }

    void AnimationStatic::resetAnimation()
    {
        animationFinished = false;
    }
}