#include "AnimationBase.hpp"

#include "../ColorsTable.hpp"

namespace animation
{
    sk6812<B, 2> AnimationBase::strip{};
    const uint8_t AnimationBase::maxNumOfPixels;
    int AnimationBase::numOfPixels{100};
    rgbw AnimationBase::pixels[maxNumOfPixels]{};
    uint8_t AnimationBase::currentColor{0};
    bool AnimationBase::on{false};
    Color AnimationBase::color{colors[currentColor]};
    int AnimationBase::middleLed{0};
    bool AnimationBase::singleMiddleLed{true};
    constexpr int16_t AnimationBase::delays[numOfDelays];
    uint8_t AnimationBase::delayIndex{0};

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

    void AnimationBase::changeSpeed()
    {
        if (delayIndex < numOfDelays - 1)
            ++delayIndex;
        else
            delayIndex = 0;
    }

    void AnimationBase::clear()
    {
        Color color{0, 0, 0, 0};
        for (int i = 0; i < maxNumOfPixels; i++)
        {
            setPixelColor(i, color);
        }
        strip.clear(maxNumOfPixels);
        resetAnimation();
    }

    void AnimationBase::setPixelColor(const int &pos, const Color &color)
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

    bool AnimationBase::continueAnimation(const unsigned long &timeToContinue) const
    {
        if (millis() > timeToContinue)
            return true;
        return false;
    }

}