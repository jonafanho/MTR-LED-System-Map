#ifndef DATA_H
#define DATA_H

#include <Arduino.h>
#include "sequence.h"

class Data
{
public:
    static constexpr uint8_t KTL_STATION_COUNT = 17;
    // WHA to TIK
    static const StationGroup KTL_1[];

private:
    static constexpr uint8_t NO_LED = 0xFF;

    static const uint8_t KTL_1_YMT_INTERCHANGES[];
    static const uint8_t KTL_1_MOK_INTERCHANGES[];
    static const uint8_t KTL_1_YAT_INTERCHANGES[];
    static const uint8_t KTL_1_TIK_INTERCHANGES[];
};

#endif
