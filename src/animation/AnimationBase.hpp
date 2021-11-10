#ifndef SRC_ANIMATION_ANIMATIONBASE
#define SRC_ANIMATION_ANIMATIONBASE
#include "../Color.hpp"
#include <FAB_LED.h>

namespace animation
{
    class IAnimation
    {
    public:
        virtual void run() = 0;
        virtual void resetAnimation() = 0;
        virtual void toogleOnOff() = 0;
        virtual void changeColor() = 0;
        virtual void clear();
    };

    class AnimationBase : public IAnimation
    {
    public:
        AnimationBase();
        void toogleOnOff() override;
        void changeColor() override;
        void clear() override;

    protected:
        void setPixelColor(int pos, Color color);
        void calculateMiddleLed();
        bool continueAnimation(unsigned long timeToContinue);

        static sk6812<B, 2> strip; //Digital Pin 10
        static const uint8_t maxNumOfPixels = 176;
        static int numOfPixels;
        static rgbw pixels[maxNumOfPixels];
        static uint8_t currentColor;
        static bool on;
        static Color color;
        static int middleLed;
        static bool singleMiddleLed;

        static const long int maxDelay = 1000;
        static const long int minDelay = 100;
        static const long int delaySteep = 100;
        static long int delay;
    };
}
#endif /* SRC_ANIMATION_ANIMATIONBASE */