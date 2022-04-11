#include "AnimationFromMiddle.hpp"

namespace animation
{
    AnimationFromMiddle::AnimationFromMiddle(config::ConfigMgr &configMgr, Strip &stripFront, Strip &stripBack, Strip &stripLeft, Strip &stripRight)
        : AnimationBase(configMgr, stripFront, stripBack, stripLeft, stripRight)
    {
        calculateDalays();
    }

    void AnimationFromMiddle::run()
    {
        if (on && !isAnimationFinished())
        {
            // TODO calculateDalays() should not be needed here because delays are calculated in Ctor and in changeSpeed()
            // TODO but for some reason delay in each strip is zero without calling calculateDalays() here
            calculateDalays();
            runStrip(stripFront, stripDataFront);
            runStrip(stripBack, stripDataBack);
            runStrip(stripLeft, stripDataLeft);
            runStrip(stripRight, stripDataRight);
            showAll();
        }
    }

    void AnimationFromMiddle::resetAnimation()
    {
        clearStripData(stripDataFront);
        clearStripData(stripDataBack);
        clearStripData(stripDataLeft);
        clearStripData(stripDataRight);

        fadedColor = CRGB{(uint8_t)(color.r / fadedFactor),
                          (uint8_t)(color.g / fadedFactor),
                          (uint8_t)(color.b / fadedFactor)};
    }

    void AnimationFromMiddle::changeSpeed()
    {
        AnimationBase::changeSpeed();
        calculateDalays();
    }

    void AnimationFromMiddle::runStrip(Strip &strip, StripData &stripData)
    {
        bool isRunning{false};
        if (continueAnimation(stripData.timeToContintue))
        {
            stripData.timeToContintue = millis() + stripData.syncDelay;
            isRunning = (isRunning) ? false : true;
        }

        if (isRunning)
        {
            if (stripData.phase == 0)
            {
                performPhase(fadedColor, strip, stripData);
            }
            else if (stripData.phase == 1)
            {
                performPhase(color, strip, stripData);
            }
            else
            {
                stripData.animationFinished = true;
            }
            isRunning = false;
        }
    }

    void AnimationFromMiddle::performPhase(const CRGB &currentColor, Strip &strip, StripData &stripData)
    {
        if (strip.singleMiddleLed)
        {
            setPixelColor(strip.middleLedIndex + stripData.ledshift, currentColor, strip);
            setPixelColor(strip.middleLedIndex - stripData.ledshift, currentColor, strip);
        }
        else
        {
            setPixelColor(strip.middleLedIndex - 1 + stripData.ledshift, currentColor, strip);
            setPixelColor(strip.middleLedIndex - stripData.ledshift, currentColor, strip);
        }
        if (stripData.ledshift == strip.middleLedIndex)
        {
            stripData.ledshift = 0;
            stripData.phase += 1;
        }
        else
            stripData.ledshift += 1;
    }

    bool AnimationFromMiddle::isAnimationFinished() const
    {
        return stripDataFront.animationFinished &&
               stripDataBack.animationFinished &&
               stripDataLeft.animationFinished &&
               stripDataRight.animationFinished;
    }

    void AnimationFromMiddle::clearStripData(StripData &strip)
    {
        strip.timeToContintue = 0;
        strip.syncDelay = 0;
        strip.animationFinished = false;
        strip.phase = 0;
        strip.ledshift = 0;
    }

    void AnimationFromMiddle::calculateDalays()
    {
        stripDataFront.syncDelay = delays[delayIndex] * ((double)stripFront.numberOfLeds / (double)stripFront.numberOfLeds);
        stripDataBack.syncDelay = delays[delayIndex] * ((double)stripFront.numberOfLeds / (double)stripBack.numberOfLeds);
        stripDataLeft.syncDelay = delays[delayIndex] * ((double)stripFront.numberOfLeds / (double)stripLeft.numberOfLeds);
        stripDataRight.syncDelay = delays[delayIndex] * ((double)stripFront.numberOfLeds / (double)stripRight.numberOfLeds);
    }
}