#ifndef SRC_ANIMATION_ANIMATIONSTATIC
#define SRC_ANIMATION_ANIMATIONSTATIC
#include "AnimationBase.hpp"

namespace animation
{
    class AnimationStatic : public AnimationBase
    {
    public:
        void run() override;
        void resetAnimation() override;

    private:
        bool animationFinished{false};
    };
}
#endif /* SRC_ANIMATION_ANIMATIONSTATIC */
