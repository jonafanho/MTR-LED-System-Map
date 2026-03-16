#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <Arduino.h>
#include <array>
#include "led.h"

struct StationGroup
{
    const uint8_t station;
    const uint8_t interchangeCount;
    const uint8_t *interchanges;
    const uint8_t arrow;
};

class Sequence
{
public:
    explicit Sequence(LED &led);

    void start(const StationGroup *stationGroups, const uint8_t stationCount);
    void next();
    void tick();

private:
    static constexpr uint16_t FLASH_FREQUENCY = 1000;

    LED &led;

    uint8_t index = 0;
    uint8_t state = 0; // Doors opened, doors closed, next station
    unsigned long nextUpdate = 0;

    const StationGroup *stationGroups = nullptr;
    uint8_t stationCount = 0;

    void setInterchanges(const StationGroup &stationGroup);
};

#endif
