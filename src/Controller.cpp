#include "Controller.hpp"

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
    if (currentAnimation < numberOfAnimaction - 1)
        ++currentAnimation;
    else
        currentAnimation = 0;
    animation[currentAnimation]->clear();
}

void Controller::changeSpeed()
{
}