#include <FAB_LED.h>
#include <Keypad.h>

#define F_EPSILON 0.00001

sk6812<B, 2> strip; //Digital Pin 10

const uint8_t maxNumOfPixels = 176;
rgbw pixels[maxNumOfPixels] = {};
float brightness = 0.20;
uint8_t numOfPixels = 33;
bool needClear = false;

struct Color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t w;
};

Color color{};

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    strip.clear(maxNumOfPixels);
}

void loop()
{
    processKey();

    tryClearLeds();
    updateColors(Color{color.r * brightness, color.g * brightness, color.b * brightness, color.w * brightness});
    strip.sendPixels(numOfPixels, pixels);
    delay(100);
}

void tryClearLeds()
{
    if (needClear)
    {
        strip.clear(maxNumOfPixels);
        needClear = false;
    }
}

void processKey()
{
    char key = keypad.getKey();
    if (key)
    {
        switch (key)
        {
        case '1':
            color = {255, 0, 0, 0};
            break;
        case '2':
            color = {0, 255, 0, 0};
            break;
        case '3':
            color = {0, 0, 255, 0};
            break;
        case '4':
            color = {0, 0, 0, 255};
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        case '0':
            break;
        case 'A':
            increaseBrightness();
            break;
        case 'B':
            decreaseBrightness();
            break;
        case 'C':
            increaseNummOfPixels();
            break;
        case 'D':
            decreaseNummOfPixels();
            break;
        case '*':
            break;
        case '#':
            break;
        default:
            break;
        }
    }
}

void increaseBrightness()
{
    if (brightness + F_EPSILON < 1.0)
        brightness += 0.05;
}

void decreaseBrightness()
{
    if (brightness > F_EPSILON)
        brightness -= 0.05;
}

void increaseNummOfPixels()
{
    if (numOfPixels < maxNumOfPixels)
        numOfPixels += 11;
}

void decreaseNummOfPixels()
{
    if (numOfPixels > 0)
        numOfPixels -= 11;
    needClear = true;
}

void updateColors(Color color)
{
    for (int i = 0; i < numOfPixels; i++)
    {
        pixels[i].r = color.r;
        pixels[i].g = color.g;
        pixels[i].b = color.b;
        pixels[i].w = color.w;
    }
}
