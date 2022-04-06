#ifndef SRC_CONFIG_CONFIG
#define SRC_CONFIG_CONFIG
#include "Arduino.h"

namespace config
{
    struct Config
    {
        uint8_t currentColorIndex;
        uint8_t delayIndex;
        uint8_t currentAnimationIndex;
    };
}

#endif /* SRC_CONFIG_CONFIG */
