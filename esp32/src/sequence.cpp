#include "sequence.h"

Sequence::Sequence(LED &led) : led(led) {}

void Sequence::start(const uint8_t *stations, const InterchangeGroup *interchangeGroups, const uint8_t *arrows, const uint8_t stationsCount)
{
    this->stations = stations;
    this->interchangeGroups = interchangeGroups;
    this->arrows = arrows;
    this->stationsCount = stationsCount;

    index = 0;
    state = 0;
}

void Sequence::next()
{
    if (stationsCount < 2)
    {
        index = 0;
        state = 0;
        return;
    }

    if (index >= stationsCount - 1)
    {
        index = stationsCount - 1;
        state = 0;
        return;
    }

    nextUpdate = 0;
    state++;

    if (state >= 3)
    {
        index++;
        state = 0;
    }
}

void Sequence::tick()
{

    if (stationsCount == 0 || index >= stationsCount || !stations || !interchangeGroups || !arrows)
    {
        return;
    }

    unsigned long currentMillis = millis();
    if ((long)(currentMillis - nextUpdate) < 0)
    {
        return;
    }

    led.clear();
    bool flash = currentMillis % FLASH_FREQUENCY < FLASH_FREQUENCY / 2;
    bool isNotLastStation = index + 1 < stationsCount;

    // This station
    if (state == 0)
    {
        led.set(stations[index]);
    }

    // This interchange
    if (state == 0 && flash)
    {
        setInterchanges(interchangeGroups[index]);
    }

    // This arrow
    if (isNotLastStation && (flash || state == 2))
    {
        led.set(arrows[index]);
    }

    // Next station
    if (isNotLastStation && (state == 0 || state == 1 || flash))
    {
        led.set(stations[index + 1]);
    }

    // Next interchange
    if (isNotLastStation && state == 2 && flash)
    {
        setInterchanges(interchangeGroups[index + 1]);
    }

    // Remaining stations
    for (uint8_t i = index + 2; i < stationsCount; i++)
    {
        led.set(stations[i]);
    }

    led.push();
    nextUpdate += FLASH_FREQUENCY / 2;
}

void Sequence::setInterchanges(const InterchangeGroup &interchangeGroup)
{
    for (uint8_t i = 0; i < interchangeGroup.count; i++)
    {
        led.set(interchangeGroup.interchanges[i]);
    }
}
