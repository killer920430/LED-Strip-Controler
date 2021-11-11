#include "Controller.hpp"

Controller::Controller() {}

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
    if (currentAnimation < numberOfAnimaction - 1)
        ++currentAnimation;
    else
        currentAnimation = 0;
    animation[currentAnimation]->clear();
}

void Controller::changeSpeed()
{
    animation[currentAnimation]->changeSpeed();
}