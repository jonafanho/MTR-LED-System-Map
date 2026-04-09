#pragma once

#include <Arduino.h>
#include <array>
#include "sequence.h"

class Data
{
public:
    static constexpr uint8_t KTL_STATION_COUNT = 17;
    static const StationGroup KTL[]; // WHA to TIK

    static constexpr uint8_t TWL_STATION_COUNT = 16;
    static const StationGroup TWL[]; // CEN to TSW

    static constexpr uint8_t ISL_STATION_COUNT = 17;
    static const StationGroup ISL[]; // KET to CHW

    static constexpr uint8_t TKL_A_STATION_COUNT = 7;
    static const StationGroup TKL_A[]; // NOP to POA

    static constexpr uint8_t TKL_B_STATION_COUNT = 6;
    static const StationGroup TKL_B[]; // NOP to LHP

private:
    static constexpr uint8_t NO_LED = 0xFF;

    static const uint8_t KTL_1_YMT_INTERCHANGES[];
    static const uint8_t KTL_1_MOK_INTERCHANGES[];
    static const uint8_t KTL_1_YAT_INTERCHANGES[];
    static const uint8_t KTL_1_TIK_INTERCHANGES[];
    static const uint8_t KTL_2_PRE_INTERCHANGES[];
    static const uint8_t KTL_2_MOK_INTERCHANGES[];

    static const uint8_t TWL_1_YMT_INTERCHANGES[];
    static const uint8_t TWL_1_MOK_INTERCHANGES[];
    static const uint8_t TWL_2_PRE_INTERCHANGES[];
    static const uint8_t TWL_2_MOK_INTERCHANGES[];
    static const uint8_t TWL_2_ADM_INTERCHANGES[];
    static const uint8_t TWL_2_CEN_INTERCHANGES[];
    static const uint8_t TWL_LAK_INTERCHANGES[];

    static const uint8_t ISL_1_CEN_INTERCHANGES[];
    static const uint8_t ISL_1_NOP_INTERCHANGES[];
    static const uint8_t ISL_2_QUB_INTERCHANGES[];
    static const uint8_t ISL_2_ADM_INTERCHANGES[];
    static const uint8_t ISL_2_CEN_INTERCHANGES[];

    static const uint8_t TKL_1_YAT_INTERCHANGES[];
    static const uint8_t TKL_2_TIK_INTERCHANGES[];
    static const uint8_t TKL_2_QUB_INTERCHANGES[];
    static const uint8_t TKL_2_NOP_INTERCHANGES[];
    static const uint8_t TKL_A_TKO_INTERCHANGES[];
    static const uint8_t TKL_B_TKO_INTERCHANGES[];
};
