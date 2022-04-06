#include "Controller.hpp"

Controller::Controller()
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