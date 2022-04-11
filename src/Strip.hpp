#ifndef SRC_STRIP
#define SRC_STRIP
#include <FastLED.h>

class Strip
{
public:
    Strip(const int &&, void (*)(CRGB *, const int));
    void setColor(const CRGB &, const int &);
    void show() const;
    void clear();

    const int numberOfLeds;

    int middleLedIndex;
    bool singleMiddleLed;

private:
    void calculateMiddleLed();

    CRGB *leds;
};

#endif /* SRC_STRIP */
