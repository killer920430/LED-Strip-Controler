#ifndef SRC_STRIPCONTROLLER
#define SRC_STRIPCONTROLLER

#define F_EPSILON 0.00001
#include <FAB_LED.h>

#include "Color.hpp"
#include "StripMode.hpp"

class StripController
{
public:
    StripController();
    void run();
    void setup();
    void tryClearLeds();
    void increaseBrightness();
    void decreaseBrightness();
    void increaseNummOfPixels();
    void decreaseNummOfPixels();
    void increaseSpeed();
    void decreaseSpeed();
    void nextColor();
    void previousColor();
    void changeMode(StripMode mode);

private:
    void calculateMiddleLed();
    void resetAnimation();
    void setPixelColor(int pos, Color color);
    void constantMode(Color color);
    void flashingMode(Color color);
    void fromMiddleMode(Color color);

    sk6812<B, 2> strip{}; //Digital Pin 10

    static constexpr uint8_t maxNumOfPixels = 176;
    rgbw pixels[maxNumOfPixels]{};
    float brightness{0.2};
    int numOfPixels{33};
    bool needClear{false};
    uint8_t currentColor{0};

    Color color;
    StripMode mode{};
    const long int maxDelay = 1000;
    const long int minDelay = 100;
    const long int delaySteep = 100;
    long int delay = maxDelay;

    int middleLed;
    bool singleMiddleLed{true};

    uint8_t phase{0};
    uint8_t ledshift{0};
};

#endif /* SRC_STRIPCONTROLLER */
