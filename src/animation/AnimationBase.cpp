#include "AnimationBase.hpp"

#include "../ColorsTable.hpp"

namespace animation
{
    uint8_t AnimationBase::currentColorIndex{0};
    bool AnimationBase::on{false};
    CRGB AnimationBase::color{colors[currentColorIndex]};
    constexpr uint16_t AnimationBase::delays[numOfDelays];
    uint8_t AnimationBase::delayIndex{2};

    AnimationBase::AnimationBase(config::ConfigMgr &configMgr, Strip &stripFront, Strip &stripBack, Strip &stripLeft, Strip &stripRight)
        : configMgr(configMgr), stripFront(stripFront), stripBack(stripBack), stripLeft(stripLeft), stripRight(stripRight)
    {
        currentColorIndex = configMgr.getColorIndex();
        color = colors[currentColorIndex];
        delayIndex = configMgr.getDelayIndex();
    }

    void AnimationBase::toogleOnOff()
    {
        if (on)
        {
            on = false;
            clear();
        }
        else
        {
            on = true;
            resetAnimation();
        }
    }

    void AnimationBase::changeColor()
    {
        if (!on)
            return;
        if (currentColorIndex < (numOfColors - 1))
            ++currentColorIndex;
        else
            currentColorIndex = 0;
        configMgr.setColorIndex(currentColorIndex);
        color = colors[currentColorIndex];
        resetAnimation();
    }

    void AnimationBase::changeSpeed()
    {
        if (!on)
            return;

        if (delayIndex < numOfDelays - 1)
            ++delayIndex;
        else
            delayIndex = 0;
        configMgr.setDelayIndex(delayIndex);
    }

    void AnimationBase::clear()
    {
        clearAll();
        resetAnimation();
    }

    bool AnimationBase::isOn() const { return on; }

    void AnimationBase::setPixelColor(const int &pos, const CRGB &color, Strip &strip)
    {
        strip.setColor(color, pos);
    }

    bool AnimationBase::continueAnimation(const unsigned long &timeToContinue) const
    {
        return (millis() > timeToContinue) ? true : false;
    }

    void AnimationBase::showAll() const
    {
        stripFront.show();
        stripBack.show();
        stripLeft.show();
        stripRight.show();
    }

    void AnimationBase::clearAll()
    {
        stripFront.clear();
        stripBack.clear();
        stripLeft.clear();
        stripRight.clear();
    }

    void AnimationBase::setStripColor(Strip &strip)
    {
        for (int i = 0; i < strip.numberOfLeds; i++)
        {
            setPixelColor(i, color, strip);
        }
    }

}