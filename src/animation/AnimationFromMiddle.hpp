#ifndef SRC_ANIMATION_ANIMATIONFROMMIDDLE
#define SRC_ANIMATION_ANIMATIONFROMMIDDLE
#include "AnimationBase.hpp"

namespace animation
{
    class AnimationFromMiddle : public AnimationBase
    {
    public:
        AnimationFromMiddle(config::ConfigMgr &, Strip &, Strip &, Strip &, Strip &);
        void run() override;
        void resetAnimation() override;

    private:
        struct StripData
        {
            unsigned long timeToContintue{0};
            int syncDelay{0};
            bool animationFinished{false};
            uint8_t phase{0};
            uint8_t ledshift{0};
        };

        void runStrip(Strip &, StripData &);
        void performPhase(const CRGB &, Strip &, StripData &);
        bool isAnimationFinished();
        void clearStripData(StripData &);

        const uint8_t fadedFactor{6};
        CRGB fadedColor{};
        StripData stripDataFront{};
        StripData stripDataBack{};
        StripData stripDataLeft{};
        StripData stripDataRight{};
    };
}

#endif /* SRC_ANIMATION_ANIMATIONFROMMIDDLE */
