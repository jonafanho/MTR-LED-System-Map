#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <Arduino.h>
#include <array>
#include "led.h"

class Sequence
{
public:
    explicit Sequence(LED &led);

    struct InterchangeGroup
    {
        uint8_t count;
        const uint8_t *interchanges;
    };

    void start(const uint8_t *stations, const InterchangeGroup *interchangeGroups, const uint8_t *arrows, const uint8_t stationsCount);
    void next();
    void tick();

private:
    static constexpr uint16_t FLASH_FREQUENCY = 1000;

    LED &led;

    uint8_t index = 0;
    uint8_t state = 0; // Doors opened, doors closed, next station
    unsigned long nextUpdate = 0;

    const uint8_t *stations = nullptr;
    const InterchangeGroup *interchangeGroups = nullptr;
    const uint8_t *arrows = nullptr;
    uint8_t stationsCount = 0;

    void setInterchanges(const InterchangeGroup &interchangeGroup);
};

#endif
