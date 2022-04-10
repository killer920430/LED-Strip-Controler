#include "AnimationFromMiddle.hpp"

namespace animation
{
    AnimationFromMiddle::AnimationFromMiddle(config::ConfigMgr &configMgr, Strip &stripFront, Strip &stripBack, Strip &stripLeft, Strip &stripRight)
        : AnimationBase(configMgr, stripFront, stripBack, stripLeft, stripRight)
    {
        // TODO FIX synchronization between strips
        stripDataBack.syncDelay = (int)((double)stripFront.numberOfLeds / (double)stripBack.numberOfLeds * 100);
        stripDataLeft.syncDelay = (int)((double)stripFront.numberOfLeds / (double)stripLeft.numberOfLeds * 100);
        stripDataRight.syncDelay = (int)((double)stripFront.numberOfLeds / (double)stripRight.numberOfLeds * 100);
    }

    void AnimationFromMiddle::run()
    {
        if (on && !isAnimationFinished())
        {
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

    void AnimationFromMiddle::runStrip(Strip &strip, StripData &stripData)
    {
        bool isRunning{false};
        if (continueAnimation(stripData.timeToContintue))
        {
            stripData.timeToContintue = millis() + delays[delayIndex] * 1 + stripData.syncDelay;
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

    bool AnimationFromMiddle::isAnimationFinished()
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
}