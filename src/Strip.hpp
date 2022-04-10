#ifndef SRC_STRIP
#define SRC_STRIP
#include <FastLED.h>

class Strip
{
public:
    Strip(const int &&);
    void setColor(const CRGB &, const int &);
    void show();
    void clear();

    const int numberOfLeds;

private:
    CRGB *leds;
};

#endif /* SRC_STRIP */
