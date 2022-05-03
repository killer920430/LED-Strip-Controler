#ifndef SRC_CONFIG_CONFIGMGR
#define SRC_CONFIG_CONFIGMGR
#include "config.hpp"

namespace config
{
    class ConfigMgr
    {
    public:
        ConfigMgr();

        uint8_t getColorIndex() const;
        void setColorIndex(const uint8_t &);
        uint8_t getDelayIndex() const;
        void setDelayIndex(const uint8_t &);
        uint8_t getAnimationIndex() const;
        void setAnimationIndex(const uint8_t &);

        void setMaxColorIndex(const uint8_t &);
        void setMaxDelayIndex(const uint8_t &);
        void setMaxAnimationIndex(const uint8_t &);

    private:
        void loadFromEeprom();
        void storeInEeprom();

        const int eeAddress{};
        Config currentConfig{};
    };
}
#endif /* SRC_CONFIG_CONFIGMGR */
