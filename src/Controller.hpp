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
    Strip strip1{30};
    uint8_t currentAnimation{0};
    static constexpr uint8_t numberOfAnimaction{3};
    config::ConfigMgr configMgr{};
    animation::IAnimation *animation[numberOfAnimaction] = {new animation::AnimationStatic(configMgr, strip1),
                                                            new animation::AnimationFlashing(configMgr, strip1),
                                                            new animation::AnimationFromMiddle(configMgr, strip1)};
};

#endif /* SRC_CONTROLLER */
