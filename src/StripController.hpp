#ifndef SRC_STRIPCONTROLLER
#define SRC_STRIPCONTROLLER

#define F_EPSILON 0.00001
#include <FAB_LED.h>

#include "Color.hpp"

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
    static void nextColor();
    static void previousColor();
    static void updateColors(Color color);

private:
    static sk6812<B, 2> strip; //Digital Pin 10

    static constexpr uint8_t maxNumOfPixels = 176;
    static rgbw pixels[maxNumOfPixels];
    static float brightness;
    static uint8_t numOfPixels;
    static bool needClear;
    static uint8_t currentColor;

    static Color color;
};

#endif /* SRC_STRIPCONTROLLER */
