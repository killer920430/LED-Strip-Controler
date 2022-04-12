#include "Controller.hpp"

Controller::Controller(RelayController &relayController) : relayController(relayController)
{
    currentAnimation = configMgr.getAnimationIndex();
}

Controller::~Controller()
{
    for (int i = 0; i < numberOfAnimaction; ++i)
        delete animation[i];
}

void Controller::run()
{
    animation[currentAnimation]->run();
}

void Controller::toogleOnOff()
{
    animation[currentAnimation]->toogleOnOff();
    if (animation[currentAnimation]->isOn())
        relayController.on();
    else
        relayController.off();
}

void Controller::changeColor()
{
    animation[currentAnimation]->changeColor();
}

void Controller::changeAnimation()
{
    if (!animation[currentAnimation]->isOn())
        return;

    if (currentAnimation < numberOfAnimaction - 1)
        ++currentAnimation;
    else
        currentAnimation = 0;
    configMgr.setAnimationIndex(currentAnimation);
    animation[currentAnimation]->clear();
}

void Controller::changeSpeed()
{
    animation[currentAnimation]->changeSpeed();
}