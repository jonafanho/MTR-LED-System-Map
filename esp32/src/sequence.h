#pragma once

#include <Arduino.h>
#include <array>
#include "led.h"

struct InterchangeGroup
{
    const uint8_t interchangeCount;
    const uint8_t *interchanges;
};

struct StationGroup
{
    const uint8_t station;
    const InterchangeGroup interchangeGroup1;
    const InterchangeGroup interchangeGroup2;
    const uint8_t arrow1;
    const uint8_t arrow2;
};

class Sequence
{
public:
    explicit Sequence(LED &led);

    void start(const StationGroup *stationGroups, const uint8_t stationCount, const bool reversed);
    bool next();
    void tick();

private:
    static constexpr uint16_t FLASH_FREQUENCY = 1000;

    LED &led;

    uint8_t index = 0;
    uint8_t state = 0; // Doors opened, doors closed, next station
    unsigned long lastMillis = 0;

    const StationGroup *stationGroups = nullptr;
    uint8_t stationCount = 0;
    bool reversed;

    void setInterchanges(const StationGroup &stationGroup);
};
