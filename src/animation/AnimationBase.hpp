#ifndef SRC_ANIMATION_ANIMATIONBASE
#define SRC_ANIMATION_ANIMATIONBASE

#include "../Strip.hpp"
#include "../config/ConfigMgr.hpp"
#include "pixeltypes.h"

namespace animation
{
    class IAnimation
    {
    public:
        virtual ~IAnimation() = default;
        virtual void run() = 0;
        virtual void resetAnimation() = 0;
        virtual void toogleOnOff() = 0;
        virtual void changeColor() = 0;
        virtual void changeSpeed() = 0;
        virtual void clear();
        virtual bool isOn() const;
    };

    class AnimationBase : public IAnimation
    {
    public:
        AnimationBase(config::ConfigMgr &, Strip &, Strip &, Strip &, Strip &);
        void toogleOnOff() override;
        void changeColor() override;
        void changeSpeed() override;
        void clear() override;
        bool isOn() const override;

    protected:
        void setPixelColor(const int &, const CRGB &, Strip &);
        bool continueAnimation(const unsigned long &) const;
        void showAll() const;
        void clearAll();
        void setStripColor(Strip &);

        config::ConfigMgr &configMgr;
        Strip &stripFront;
        Strip &stripBack;
        Strip &stripLeft;
        Strip &stripRight;

        static uint8_t currentColorIndex;
        static bool on;
        static CRGB color;
        static const uint8_t numOfDelays = 7;
        static constexpr uint16_t delays[numOfDelays]{50, 100, 150, 200, 250, 300, 350};
        static uint8_t delayIndex;
    };
}
#endif /* SRC_ANIMATION_ANIMATIONBASE */
