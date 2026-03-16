#include "led.h"
#include <SPI.h>

void LED::init(const uint8_t brightness)
{
    pinMode(PIN_LATCH, OUTPUT);
    digitalWrite(PIN_LATCH, HIGH);

    pinMode(PIN_RESET, OUTPUT);
    digitalWrite(PIN_RESET, HIGH);

    SPI.begin(PIN_CLK, -1, PIN_DATA, -1);

    ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
    ledcAttachPin(PIN_PWM, PWM_CHANNEL);
    setBrightness(brightness);

    clear();
    push();
}

void LED::setBrightness(uint8_t brightness)
{
    ledcWrite(PWM_CHANNEL, 0xFF - brightness);
}

void LED::set(uint8_t position)
{
    uint8_t index = position / 8;
    if (index < COUNT_595)
    {
        buffer[COUNT_595 - index - 1] |= (1 << (position % 8));
    }
}

void LED::clear()
{
    buffer.fill(0);
}

void LED::push()
{
    SPI.beginTransaction(SPISettings(SPI_SPEED, MSBFIRST, SPI_MODE0));
    digitalWrite(PIN_LATCH, LOW);
    SPI.transfer(buffer.data(), buffer.size());
    digitalWrite(PIN_LATCH, HIGH);
    SPI.endTransaction();
}
