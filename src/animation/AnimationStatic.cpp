#include "AnimationStatic.hpp"

namespace animation
{
    AnimationStatic::AnimationStatic(config::ConfigMgr &configMgr, Strip &stripFront, Strip &stripBack, Strip &stripLeft, Strip &stripRight)
        : AnimationBase(configMgr, stripFront, stripBack, stripLeft, stripRight) {}

    void AnimationStatic::run()
    {
        AnimationBase::run();
        if (on && not animationFinished)
        {
            setStripColor(stripFront);
            setStripColor(stripBack);
            setStripColor(stripLeft);
            setStripColor(stripRight);
            showAll();
            animationFinished = true;
        }
    }

    void AnimationStatic::resetAnimation()
    {
        animationFinished = false;
    }
}