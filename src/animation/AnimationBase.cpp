#include "AnimationBase.hpp"

#include "../ColorsTable.hpp"

namespace animation
{
    sk6812<B, 2> AnimationBase::strip{};
    const uint8_t AnimationBase::maxNumOfPixels;
    int AnimationBase::numOfPixels{33};
    rgbw AnimationBase::pixels[maxNumOfPixels]{};
    uint8_t AnimationBase::currentColor{0};
    bool AnimationBase::on{false};
    Color AnimationBase::color{colors[currentColor]};
    int AnimationBase::middleLed{0};
    bool AnimationBase::singleMiddleLed{true};
    long int AnimationBase::delay = maxDelay;

    AnimationBase::AnimationBase()
    {
        calculateMiddleLed();
    }

    void AnimationBase::toogleOnOff()
    {
        if (on)
        {
            on = false;
            strip.clear(maxNumOfPixels);
        }
        else
        {
            on = true;
            resetAnimation();
        }
    }

    void AnimationBase::changeColor()
    {
        if (currentColor < (numOfColors - 1))
            ++currentColor;
        else
            currentColor = 0;
        color = colors[currentColor];
        resetAnimation();
    }

    void AnimationBase::clear()
    {
        strip.clear(maxNumOfPixels);
    }

    void AnimationBase::setPixelColor(int pos, Color color)
    {
        pixels[pos].r = color.r;
        pixels[pos].g = color.g;
        pixels[pos].b = color.b;
        pixels[pos].w = color.w;
    }

    void AnimationBase::calculateMiddleLed()
    {
        middleLed = numOfPixels / 2;
        if (numOfPixels % 2)
            singleMiddleLed = true;
        else
            singleMiddleLed = false;
    }

    bool AnimationBase::continueAnimation(unsigned long timeToContinue)
    {
        if (millis() > timeToContinue)
            return true;
        return false;
    }

}