#ifndef SRC_STRIPCONTROLLER
#define SRC_STRIPCONTROLLER

#define F_EPSILON 0.00001
#include <FAB_LED.h>

#include "Color.hpp"
#include "StripMode.hpp"

class StripController
{
public:
    void run();
    void setup();
    static void tryClearLeds();
    static void increaseBrightness();
    static void decreaseBrightness();
    static void increaseNummOfPixels();
    static void decreaseNummOfPixels();
    static void increaseSpeed();
    static void decreaseSpeed();
    static void nextColor();
    static void previousColor();
    static void changeMode(StripMode mode);

private:
    void constantMode(Color color);
    void flashingMode(Color color);

    static sk6812<B, 2> strip; //Digital Pin 10

    static constexpr uint8_t maxNumOfPixels = 176;
    static rgbw pixels[maxNumOfPixels];
    static float brightness;
    static uint8_t numOfPixels;
    static bool needClear;
    static uint8_t currentColor;

    static Color color;
    static StripMode mode;
    static constexpr long int maxDelay = 1000;
    static constexpr long int minDelay = 100;
    static constexpr long int delaySteep = 100;
    static long int delay;
};

#endif /* SRC_STRIPCONTROLLER */
