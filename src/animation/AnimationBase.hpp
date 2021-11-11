#ifndef SRC_ANIMATION_ANIMATIONBASE
#define SRC_ANIMATION_ANIMATIONBASE
#include <FAB_LED.h>

#include "../Color.hpp"

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
    };

    class AnimationBase : public IAnimation
    {
    public:
        AnimationBase();
        void toogleOnOff() override;
        void changeColor() override;
        void changeSpeed() override;
        void clear() override;

    protected:
        void setPixelColor(const int &pos, const Color &color);
        void calculateMiddleLed();
        bool continueAnimation(const unsigned long &timeToContinue) const;

        static sk6812<B, 2> strip; //Digital Pin 10
        static const uint8_t maxNumOfPixels = 176;
        static int numOfPixels;
        static rgbw pixels[maxNumOfPixels];
        static uint8_t currentColor;
        static bool on;
        static Color color;
        static int middleLed;
        static bool singleMiddleLed;

        static const uint8_t numOfDelays = 7;
        static constexpr int16_t delays[numOfDelays]{1, 50, 100, 150, 200, 250, 300};
        static uint8_t delayIndex;
    };
}
#endif /* SRC_ANIMATION_ANIMATIONBASE */
