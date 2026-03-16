#include "sequence.h"

Sequence::Sequence(LED &led) : led(led) {}

void Sequence::start(const StationGroup *stationGroups, const uint8_t stationCount)
{
    this->stationGroups = stationGroups;
    this->stationCount = stationCount;

    index = 0;
    state = 0;
}

void Sequence::next()
{
    if (stationCount < 2)
    {
        index = 0;
        state = 0;
        return;
    }

    if (index >= stationCount - 1)
    {
        index = stationCount - 1;
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

    if (stationCount == 0 || index >= stationCount || !stationGroups)
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
    bool isNotLastStation = index + 1 < stationCount;

    // This station
    if (state == 0)
    {
        led.set(stationGroups[index].station);
    }

    // This interchange
    if (state == 0 && flash)
    {
        setInterchanges(stationGroups[index]);
    }

    // This arrow
    if (isNotLastStation && (flash || state == 2))
    {
        led.set(stationGroups[index].arrow);
    }

    // Next station
    if (isNotLastStation && (state == 0 || state == 1 || flash))
    {
        led.set(stationGroups[index + 1].station);
    }

    // Next interchange
    if (isNotLastStation && state == 2 && flash)
    {
        setInterchanges(stationGroups[index + 1]);
    }

    // Remaining stations
    for (uint8_t i = index + 2; i < stationCount; i++)
    {
        led.set(stationGroups[i].station);
    }

    led.push();
    nextUpdate = currentMillis + FLASH_FREQUENCY / 2;
}

void Sequence::setInterchanges(const StationGroup &stationGroup)
{

    if (stationGroup.interchanges)
    {
        for (uint8_t i = 0; i < stationGroup.interchangeCount; i++)
        {
            led.set(stationGroup.interchanges[i]);
        }
    }
}
