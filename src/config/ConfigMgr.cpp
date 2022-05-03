#include "ConfigMgr.hpp"

#include <EEPROM.h>

namespace config
{
    ConfigMgr::ConfigMgr() { loadFromEeprom(); }

    uint8_t ConfigMgr::getColorIndex() const { return currentConfig.currentColorIndex; }

    void ConfigMgr::setColorIndex(const uint8_t &colorIdx)
    {
        currentConfig.currentColorIndex = colorIdx;
        storeInEeprom();
    }

    uint8_t ConfigMgr::getDelayIndex() const { return currentConfig.delayIndex; }

    void ConfigMgr::setDelayIndex(const uint8_t &delayIdx)
    {
        currentConfig.delayIndex = delayIdx;
        storeInEeprom();
    }

    uint8_t ConfigMgr::getAnimationIndex() const { return currentConfig.currentAnimationIndex; }

    void ConfigMgr::setAnimationIndex(const uint8_t &animationIdx)
    {
        currentConfig.currentAnimationIndex = animationIdx;
        storeInEeprom();
    }

    void ConfigMgr::setMaxColorIndex(const uint8_t &maxColorIndex)
    {
        if (currentConfig.currentColorIndex > maxColorIndex)
            setColorIndex(0);
    }

    void ConfigMgr::setMaxDelayIndex(const uint8_t &maxDelayIndex)
    {
        if (currentConfig.delayIndex > maxDelayIndex)
            setDelayIndex(0);
    }

    void ConfigMgr::setMaxAnimationIndex(const uint8_t &maxAnimationIndex)
    {
        if (currentConfig.currentAnimationIndex > maxAnimationIndex)
            setAnimationIndex(0);
    }

    void ConfigMgr::loadFromEeprom()
    {
        EEPROM.get(eeAddress, currentConfig);
    }

    void ConfigMgr::storeInEeprom()
    {
        EEPROM.put(eeAddress, currentConfig);
    }

}
