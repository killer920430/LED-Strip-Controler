#ifndef SRC_CONTROLLER
#define SRC_CONTROLLER
#include "animation/AnimationFlashing.hpp"
#include "animation/AnimationFromMiddle.hpp"
#include "animation/AnimationStatic.hpp"

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
    uint8_t currentAnimation{0};
    static constexpr uint8_t numberOfAnimaction{3};
    animation::IAnimation *animation[numberOfAnimaction] = {new animation::AnimationStatic(),
                                                            new animation::AnimationFlashing(),
                                                            new animation::AnimationFromMiddle()};
};

#endif /* SRC_CONTROLLER */
