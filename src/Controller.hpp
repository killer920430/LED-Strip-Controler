#ifndef SRC_CONTROLLER
#define SRC_CONTROLLER
#include "PinConfiguration.hpp"
#include "RelayController.hpp"
#include "Strip.hpp"
#include "animation/AnimationFlashing.hpp"
#include "animation/AnimationFromMiddle.hpp"
#include "animation/AnimationStatic.hpp"
#include "config/ConfigMgr.hpp"

class Controller
{
public:
    Controller(RelayController &relayController);
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
    RelayController &relayController;
    Strip stripFront{30, [](CRGB *leds, const int numberOfLeds)
                     { FastLED.addLeds<NEOPIXEL, LED_STRIP_1_PIN>(leds, numberOfLeds); }};
    Strip stripBack{60, [](CRGB *leds, const int numberOfLeds)
                    { FastLED.addLeds<NEOPIXEL, LED_STRIP_2_PIN>(leds, numberOfLeds); }};
    Strip stripLeft{40, [](CRGB *leds, const int numberOfLeds)
                    { FastLED.addLeds<NEOPIXEL, LED_STRIP_3_PIN>(leds, numberOfLeds); }};
    Strip stripRight{50, [](CRGB *leds, const int numberOfLeds)
                     { FastLED.addLeds<NEOPIXEL, LED_STRIP_4_PIN>(leds, numberOfLeds); }};
    uint8_t currentAnimation{0};
    static constexpr uint8_t numberOfAnimaction{3};
    config::ConfigMgr configMgr{};
    animation::IAnimation *animation[numberOfAnimaction] = {new animation::AnimationStatic(configMgr, stripFront, stripBack, stripLeft, stripRight),
                                                            new animation::AnimationFlashing(configMgr, stripFront, stripBack, stripLeft, stripRight),
                                                            new animation::AnimationFromMiddle(configMgr, stripFront, stripBack, stripLeft, stripRight)};
};

#endif /* SRC_CONTROLLER */
