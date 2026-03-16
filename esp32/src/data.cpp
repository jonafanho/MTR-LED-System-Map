#include "data.h"

const uint8_t Data::KTL_1_YMT_INTERCHANGES[] = {8 * 8 + 1, 3 * 8 + 1};
const uint8_t Data::KTL_1_MOK_INTERCHANGES[] = {7 * 8, 0};
const uint8_t Data::KTL_1_YAT_INTERCHANGES[] = {17 * 8 + 5, 17 * 8 + 6};
const uint8_t Data::KTL_1_TIK_INTERCHANGES[] = {17 * 8 + 4, 17 * 8, 22 * 8};
const StationGroup Data::KTL_1[] = {
    {12 * 8 + 4, 0, nullptr, 12 * 8 + 3},
    {12 * 8 + 1, 0, nullptr, 9 * 8 + 7},
    {9 * 8 + 5, 2, Data::KTL_1_YMT_INTERCHANGES, 9 * 8 + 4},
    {9 * 8 + 2, 2, Data::KTL_1_MOK_INTERCHANGES, 9 * 8 + 1},
    {10 * 8 + 7, 0, nullptr, 10 * 8 + 6},
    {10 * 8 + 4, 0, nullptr, 10 * 8 + 3},
    {10 * 8 + 1, 0, nullptr, 11 * 8 + 7},
    {11 * 8 + 5, 0, nullptr, 11 * 8 + 4},
    {11 * 8 + 2, 0, nullptr, 11 * 8 + 1},
    {15 * 8 + 7, 0, nullptr, 15 * 8 + 6},
    {15 * 8 + 4, 0, nullptr, 15 * 8 + 3},
    {15 * 8 + 1, 0, nullptr, 18 * 8 + 7},
    {18 * 8 + 5, 0, nullptr, 18 * 8 + 4},
    {18 * 8 + 2, 0, nullptr, 18 * 8 + 1},
    {19 * 8 + 7, 0, nullptr, 19 * 8 + 6},
    {19 * 8 + 4, 2, Data::KTL_1_YAT_INTERCHANGES, 19 * 8 + 3},
    {19 * 8 + 1, 3, Data::KTL_1_TIK_INTERCHANGES, NO_LED},
};
