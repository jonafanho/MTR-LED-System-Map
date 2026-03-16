#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <array>

class LED
{
public:
    void init(const uint8_t brightness);
    void setBrightness(uint8_t brightness);
    void set(uint8_t position);
    void clear();
    void push();

private:
    static constexpr uint8_t PIN_DATA = 4;
    static constexpr uint8_t PIN_CLK = 7;
    static constexpr uint8_t PIN_RESET = 8;
    static constexpr uint8_t PIN_LATCH = 9;
    static constexpr uint8_t PIN_PWM = 10;

    static constexpr uint8_t COUNT_595 = 24;
    static constexpr uint8_t PWM_CHANNEL = 0;
    static constexpr uint8_t PWM_RESOLUTION = 8;
    static constexpr uint32_t PWM_FREQUENCY = 20000;
    static constexpr uint32_t SPI_SPEED = 8000000;

    std::array<uint8_t, COUNT_595> buffer{};
};

#endif
