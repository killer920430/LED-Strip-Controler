#ifndef SRC_CONTROLLER
#define SRC_CONTROLLER
#include "Strip.hpp"
#include "animation/AnimationFlashing.hpp"
#include "animation/AnimationFromMiddle.hpp"
#include "animation/AnimationStatic.hpp"
#include "config/ConfigMgr.hpp"

class Controller
{
public:
    Controller();
    Controller(const Controller &) = delete;
    Controller(Controller &&) = delete;
    Controller &operator=(const Controller &) = delete;
    Controller &operator=(Controller &&) = delete;
    ~Controller();
    void run();
    void toogleOnOff();
    void changeColor();
    void changeAnimation();
    void changeSpeed();

private:
    Strip stripFront{30, [](CRGB *leds, const int numberOfLeds)
                     { FastLED.addLeds<NEOPIXEL, 10>(leds, numberOfLeds); }};
    Strip stripBack{60, [](CRGB *leds, const int numberOfLeds)
                    { FastLED.addLeds<NEOPIXEL, 9>(leds, numberOfLeds); }};
    Strip stripLeft{40, [](CRGB *leds, const int numberOfLeds)
                    { FastLED.addLeds<NEOPIXEL, 7>(leds, numberOfLeds); }};
    Strip stripRight{50, [](CRGB *leds, const int numberOfLeds)
                     { FastLED.addLeds<NEOPIXEL, 6>(leds, numberOfLeds); }};
    uint8_t currentAnimation{0};
    static constexpr uint8_t numberOfAnimaction{3};
    config::ConfigMgr configMgr{};
    animation::IAnimation *animation[numberOfAnimaction] = {new animation::AnimationStatic(configMgr, stripFront, stripBack, stripLeft, stripRight),
                                                            new animation::AnimationFlashing(configMgr, stripFront, stripBack, stripLeft, stripRight),
                                                            new animation::AnimationFromMiddle(configMgr, stripFront, stripBack, stripLeft, stripRight)};
};

#endif /* SRC_CONTROLLER */
