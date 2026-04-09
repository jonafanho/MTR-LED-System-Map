#include "data.h"

const uint8_t Data::KTL_1_YMT_INTERCHANGES[] = {8 * 8 + 1, 3 * 8 + 1};
const uint8_t Data::KTL_1_MOK_INTERCHANGES[] = {7 * 8, 0};
const uint8_t Data::KTL_1_YAT_INTERCHANGES[] = {17 * 8 + 5, 17 * 8 + 6};
const uint8_t Data::KTL_1_TIK_INTERCHANGES[] = {17 * 8 + 4, 17 * 8, 22 * 8};
const uint8_t Data::KTL_2_PRE_INTERCHANGES[] = {0};
const uint8_t Data::KTL_2_MOK_INTERCHANGES[] = {7 * 8, 8 * 8 + 1, 3 * 8 + 1};
const StationGroup Data::KTL[] = {
    {12 * 8 + 4, {0, nullptr}, {0, nullptr}, 12 * 8 + 3, NO_LED},
    {12 * 8 + 1, {0, nullptr}, {0, nullptr}, 9 * 8 + 7, 12 * 8 + 2},
    {9 * 8 + 5, {2, Data::KTL_1_YMT_INTERCHANGES}, {0, nullptr}, 9 * 8 + 4, 9 * 8 + 6},
    {9 * 8 + 2, {2, Data::KTL_1_MOK_INTERCHANGES}, {3, KTL_2_MOK_INTERCHANGES}, 9 * 8 + 1, 9 * 8 + 3},
    {10 * 8 + 7, {0, nullptr}, {1, KTL_2_PRE_INTERCHANGES}, 10 * 8 + 6, 9 * 8},
    {10 * 8 + 4, {0, nullptr}, {0, nullptr}, 10 * 8 + 3, 10 * 8 + 5},
    {10 * 8 + 1, {0, nullptr}, {0, nullptr}, 11 * 8 + 7, 10 * 8 + 2},
    {11 * 8 + 5, {0, nullptr}, {0, nullptr}, 11 * 8 + 4, 11 * 8 + 6},
    {11 * 8 + 2, {0, nullptr}, {0, nullptr}, 11 * 8 + 1, 11 * 8 + 3},
    {15 * 8 + 7, {0, nullptr}, {0, nullptr}, 15 * 8 + 6, 11 * 8},
    {15 * 8 + 4, {0, nullptr}, {0, nullptr}, 15 * 8 + 3, 15 * 8 + 5},
    {15 * 8 + 1, {0, nullptr}, {0, nullptr}, 18 * 8 + 7, 15 * 8 + 2},
    {18 * 8 + 5, {0, nullptr}, {0, nullptr}, 18 * 8 + 4, 18 * 8 + 6},
    {18 * 8 + 2, {0, nullptr}, {0, nullptr}, 18 * 8 + 1, 18 * 8 + 3},
    {19 * 8 + 7, {0, nullptr}, {0, nullptr}, 19 * 8 + 6, 18 * 8},
    {19 * 8 + 4, {2, Data::KTL_1_YAT_INTERCHANGES}, {0, nullptr}, 19 * 8 + 3, 19 * 8 + 5},
    {19 * 8 + 1, {3, Data::KTL_1_TIK_INTERCHANGES}, {0, nullptr}, NO_LED, 19 * 8 + 2},
};

const uint8_t Data::TWL_1_YMT_INTERCHANGES[] = {12 * 8};
const uint8_t Data::TWL_1_MOK_INTERCHANGES[] = {10 * 8, 15 * 8, 19 * 8};
const uint8_t Data::TWL_2_PRE_INTERCHANGES[] = {15 * 8, 19 * 8};
const uint8_t Data::TWL_2_MOK_INTERCHANGES[] = {10 * 8, 12 * 8};
const uint8_t Data::TWL_2_ADM_INTERCHANGES[] = {8 * 8, 23 * 8};
const uint8_t Data::TWL_2_CEN_INTERCHANGES[] = {2 * 8, 4 * 8};
const uint8_t Data::TWL_LAK_INTERCHANGES[] = {4 * 8};
const StationGroup Data::TWL[] = {
    {3 * 8, {0, nullptr}, {2, TWL_2_CEN_INTERCHANGES}, 5 * 8 + 7, NO_LED},
    {5 * 8 + 2, {0, nullptr}, {2, TWL_2_ADM_INTERCHANGES}, 5 * 8 + 1, 5 * 8 + 4},
    {8 * 8 + 4, {0, nullptr}, {0, nullptr}, 8 * 8 + 3, 8 * 8 + 5},
    {7 * 8 + 7, {0, nullptr}, {0, nullptr}, 7 * 8 + 6, 8 * 8 + 2},
    {7 * 8 + 4, {1, TWL_1_YMT_INTERCHANGES}, {0, nullptr}, 7 * 8 + 3, 7 * 8 + 5},
    {7 * 8 + 1, {3, TWL_1_MOK_INTERCHANGES}, {2, TWL_2_MOK_INTERCHANGES}, 6 * 8 + 7, 7 * 8 + 2},
    {6 * 8 + 5, {0, nullptr}, {2, TWL_2_PRE_INTERCHANGES}, 6 * 8 + 4, 6 * 8 + 6},
    {6 * 8 + 2, {0, nullptr}, {0, nullptr}, 6 * 8 + 1, 6 * 8 + 3},
    {4 * 8 + 7, {0, nullptr}, {0, nullptr}, 4 * 8 + 6, 6 * 8},
    {4 * 8 + 4, {0, nullptr}, {0, nullptr}, 4 * 8 + 3, 4 * 8 + 5},
    {4 * 8 + 1, {0, nullptr}, {0, nullptr}, 1 * 8 + 7, 4 * 8 + 2},
    {1 * 8 + 5, {1, TWL_LAK_INTERCHANGES}, {1, TWL_LAK_INTERCHANGES}, 1 * 8 + 4, 1 * 8 + 6},
    {1 * 8 + 2, {0, nullptr}, {0, nullptr}, 1 * 8 + 1, 1 * 8 + 3},
    {7, {0, nullptr}, {0, nullptr}, 6, 1 * 8},
    {4, {0, nullptr}, {0, nullptr}, 3, 5},
    {1, {0, nullptr}, {0, nullptr}, NO_LED, 2},
};

const uint8_t Data::ISL_1_CEN_INTERCHANGES[] = {3 * 8 + 1, 8 * 8 + 1, 7 * 8, 0, 4 * 8};
const uint8_t Data::ISL_1_NOP_INTERCHANGES[] = {17 * 8 + 6, 17 * 8 + 5, 17 * 8 + 4, 17 * 8, 22 * 8};
const uint8_t Data::ISL_2_QUB_INTERCHANGES[] = {17 * 8 + 5, 17 * 8 + 4, 17 * 8, 22 * 8};
const uint8_t Data::ISL_2_ADM_INTERCHANGES[] = {8 * 8 + 1, 7 * 8, 0};
const uint8_t Data::ISL_2_CEN_INTERCHANGES[] = {4 * 8};
const StationGroup Data::ISL[] = {
    {2 * 8 + 7, {0, nullptr}, {0, nullptr}, 2 * 8 + 6, NO_LED},
    {2 * 8 + 4, {0, nullptr}, {0, nullptr}, 2 * 8 + 3, 2 * 8 + 5},
    {2 * 8 + 1, {0, nullptr}, {0, nullptr}, 3 * 8 + 7, 2 * 8 + 2},
    {3 * 8 + 5, {0, nullptr}, {0, nullptr}, 3 * 8 + 4, 3 * 8 + 6},
    {3 * 8 + 2, {5, ISL_1_CEN_INTERCHANGES}, {1, ISL_2_CEN_INTERCHANGES}, 5 * 8 + 6, 3 * 8 + 3},
    {5 * 8 + 3, {0, nullptr}, {3, ISL_2_ADM_INTERCHANGES}, 5 * 8, 5 * 8 + 5},
    {8 * 8 + 7, {0, nullptr}, {0, nullptr}, 13 * 8 + 7, 8 * 8 + 6},
    {13 * 8 + 5, {0, nullptr}, {0, nullptr}, 13 * 8 + 4, 13 * 8 + 6},
    {13 * 8 + 2, {0, nullptr}, {0, nullptr}, 13 * 8 + 1, 13 * 8 + 3},
    {12 * 8 + 7, {0, nullptr}, {0, nullptr}, 12 * 8 + 6, 13 * 8},
    {14 * 8 + 7, {5, ISL_1_NOP_INTERCHANGES}, {0, nullptr}, 14 * 8 + 5, 12 * 8 + 5},
    {14 * 8, {0, nullptr}, {4, ISL_2_QUB_INTERCHANGES}, 20 * 8 + 7, 14 * 8 + 2},
    {20 * 8 + 5, {0, nullptr}, {0, nullptr}, 20 * 8 + 4, 20 * 8 + 6},
    {20 * 8 + 2, {0, nullptr}, {0, nullptr}, 20 * 8 + 1, 20 * 8 + 3},
    {23 * 8 + 7, {0, nullptr}, {0, nullptr}, 23 * 8 + 6, 20 * 8},
    {23 * 8 + 4, {0, nullptr}, {0, nullptr}, 23 * 8 + 3, 23 * 8 + 5},
    {23 * 8 + 1, {0, nullptr}, {0, nullptr}, NO_LED, 23 * 8 + 2},
};

const uint8_t Data::TKL_1_YAT_INTERCHANGES[] = {15 * 8, 10 * 8, 12 * 8};
const uint8_t Data::TKL_2_TIK_INTERCHANGES[] = {19 * 8, 15 * 8, 10 * 8, 12 * 8};
const uint8_t Data::TKL_2_QUB_INTERCHANGES[] = {23 * 8};
const uint8_t Data::TKL_2_NOP_INTERCHANGES[] = {8 * 8, 2 * 8};
const uint8_t Data::TKL_A_TKO_INTERCHANGES[] = {17 * 8};
const uint8_t Data::TKL_B_TKO_INTERCHANGES[] = {22 * 8};
const StationGroup Data::TKL_A[] = {
    {14 * 8 + 6, {0, nullptr}, {2, TKL_2_NOP_INTERCHANGES}, 14 * 8 + 4, NO_LED},
    {14 * 8 + 1, {0, nullptr}, {1, TKL_2_QUB_INTERCHANGES}, 17 * 8 + 3, 14 * 8 + 3},
    {17 * 8 + 1, {3, TKL_1_YAT_INTERCHANGES}, {0, nullptr}, 21 * 8 + 7, 17 * 8 + 2},
    {21 * 8 + 5, {0, nullptr}, {4, TKL_2_TIK_INTERCHANGES}, 21 * 8 + 4, 21 * 8 + 6},
    {21 * 8 + 2, {1, TKL_A_TKO_INTERCHANGES}, {1, TKL_A_TKO_INTERCHANGES}, 22 * 8 + 6, 21 * 8 + 3},
    {22 * 8 + 4, {0, nullptr}, {0, nullptr}, 22 * 8 + 3, 22 * 8 + 5},
    {22 * 8 + 1, {0, nullptr}, {0, nullptr}, NO_LED, 22 * 8 + 2},
};
const StationGroup Data::TKL_B[] = {
    {14 * 8 + 6, {0, nullptr}, {2, TKL_2_NOP_INTERCHANGES}, 14 * 8 + 4, NO_LED},
    {14 * 8 + 1, {0, nullptr}, {1, TKL_2_QUB_INTERCHANGES}, 17 * 8 + 3, 14 * 8 + 3},
    {17 * 8 + 1, {3, TKL_1_YAT_INTERCHANGES}, {0, nullptr}, 21 * 8 + 7, 17 * 8 + 2},
    {21 * 8 + 5, {0, nullptr}, {4, TKL_2_TIK_INTERCHANGES}, 21 * 8 + 4, 21 * 8 + 6},
    {21 * 8 + 2, {1, TKL_B_TKO_INTERCHANGES}, {1, TKL_B_TKO_INTERCHANGES}, 21 * 8 + 1, 21 * 8 + 3},
    {22 * 8 + 7, {0, nullptr}, {0, nullptr}, NO_LED, 21 * 8},
};
