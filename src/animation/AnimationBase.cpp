#include "AnimationBase.hpp"

#include "../ColorsTable.hpp"

namespace animation
{
    uint8_t AnimationBase::currentColorIndex{0};
    bool AnimationBase::on{false};
    CRGB AnimationBase::color{colors[currentColorIndex]};
    int AnimationBase::middleLedIndex{0};
    bool AnimationBase::singleMiddleLed{true};
    constexpr uint16_t AnimationBase::delays[numOfDelays];
    uint8_t AnimationBase::delayIndex{2};

    AnimationBase::AnimationBase(config::ConfigMgr &configMgr, Strip &strip) : configMgr(configMgr), strip(strip)
    {
        currentColorIndex = configMgr.getColorIndex();
        color = colors[currentColorIndex];
        delayIndex = configMgr.getDelayIndex();
        calculateMiddleLed();
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
        strip.clear();
        resetAnimation();
    }

    bool AnimationBase::isOn() { return on; }

    void AnimationBase::setPixelColor(const int &pos, const CRGB &color)
    {
        strip.setColor(color, pos);
    }

    void AnimationBase::calculateMiddleLed()
    {
        middleLedIndex = strip.numberOfLeds / 2;
        singleMiddleLed = (strip.numberOfLeds % 2) ? true : false;
    }

    bool AnimationBase::continueAnimation(const unsigned long &timeToContinue) const
    {
        return (millis() > timeToContinue) ? true : false;
    }

}