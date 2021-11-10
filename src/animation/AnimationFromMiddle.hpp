#ifndef SRC_ANIMATION_ANIMATIONFROMMIDDLE
#define SRC_ANIMATION_ANIMATIONFROMMIDDLE
#include "AnimationBase.hpp"

namespace animation
{
    class AnimationFromMiddle : public AnimationBase
    {
    public:
        void run() override;
        void resetAnimation() override;

    private:
        uint8_t phase{0};
        uint8_t ledshift{0};
    };
}

#endif /* SRC_ANIMATION_ANIMATIONFROMMIDDLE */
