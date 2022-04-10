#ifndef SRC_ANIMATION_ANIMATIONFLASHING
#define SRC_ANIMATION_ANIMATIONFLASHING
#include "AnimationBase.hpp"

namespace animation
{
    class AnimationFlashing : public AnimationBase
    {
    public:
        AnimationFlashing(config::ConfigMgr &, Strip &);
        void run() override;
        void resetAnimation() override;
    };
}

#endif /* SRC_ANIMATION_ANIMATIONFLASHING */
