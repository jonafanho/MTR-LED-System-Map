#include "sequence.h"

Sequence::Sequence(LED &led) : led(led) {}

void Sequence::start(const StationGroup *stationGroups, const uint8_t stationCount, const bool reversed)
{
    this->stationGroups = stationGroups;
    this->stationCount = stationCount;
    this->reversed = reversed;

    index = 0;
    state = 0;
}

bool Sequence::next()
{
    if (stationCount < 2)
    {
        index = 0;
        state = 0;
        return true;
    }

    if (index >= stationCount - 1)
    {
        index = stationCount - 1;
        state = 0;
        return true;
    }

    lastMillis = 0;
    state++;

    if (state >= 3)
    {
        index++;
        state = 0;
    }

    return false;
}

void Sequence::tick()
{

    if (stationCount == 0 || index >= stationCount || !stationGroups)
    {
        return;
    }

    unsigned long currentMillis = millis();
    if (lastMillis / (FLASH_FREQUENCY / 2) != currentMillis / (FLASH_FREQUENCY / 2))
    {
        led.clear();
        bool flash = currentMillis % FLASH_FREQUENCY < FLASH_FREQUENCY / 2;
        int index1 = reversed ? (int)stationCount - (int)index - 1 : (int)index;
        int step = reversed ? -1 : 1;
        int index2 = index1 + step;
        int index3 = index1 + 2 * step;
        bool isNotLastStation = index2 >= 0 && index2 < stationCount;

        // This station
        if (state == 0)
        {
            led.set(stationGroups[index1].station);
        }

        // This interchange
        if (state == 0 && flash)
        {
            setInterchanges(stationGroups[index1]);
        }

        // This arrow
        if (isNotLastStation && (flash || state == 2))
        {
            led.set(reversed ? stationGroups[index1].arrow2 : stationGroups[index1].arrow1);
        }

        // Next station
        if (isNotLastStation && (state == 0 || state == 1 || flash))
        {
            led.set(stationGroups[index2].station);
        }

        // Next interchange
        if (isNotLastStation && state == 2 && flash)
        {
            setInterchanges(stationGroups[index2]);
        }

        // Remaining stations
        for (int i = index3; reversed ? (i >= 0) : (i < stationCount); i += step)
        {
            led.set(stationGroups[i].station);
        }

        led.push();
    }

    lastMillis = currentMillis;
}

void Sequence::setInterchanges(const StationGroup &stationGroup)
{
    const InterchangeGroup &interchangeGroup = reversed ? stationGroup.interchangeGroup2 : stationGroup.interchangeGroup1;
    if (interchangeGroup.interchangeCount > 0)
    {
        for (uint8_t i = 0; i < interchangeGroup.interchangeCount; i++)
        {
            led.set(interchangeGroup.interchanges[i]);
        }
    }
}
