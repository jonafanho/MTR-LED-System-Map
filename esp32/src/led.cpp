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
    shift();
}

void LED::setBrightness(uint8_t brightness)
{
    ledcWrite(PWM_CHANNEL, 0xFF - brightness);
}

void LED::clear()
{
    buffer.fill(0xFF);
}

void LED::shift()
{
    SPI.beginTransaction(SPISettings(SPI_SPEED, MSBFIRST, SPI_MODE0));
    digitalWrite(PIN_LATCH, LOW);
    SPI.transfer(buffer.data(), buffer.size());
    digitalWrite(PIN_LATCH, HIGH);
    SPI.endTransaction();
}
