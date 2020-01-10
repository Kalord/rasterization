#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sys/types.h>

#include "../core/BitMap.hpp"

class Rasterization
{
public:
    /**
     * Алгоритм DDA-Line
     **/
    static void DDALine(
        BitMap& bitMap,
        std::pair<float, float> onePoint,
        std::pair<float, float> twoPoint
    );

    /**
     * Алгоритм Брезенхэма
     **/
    static void bresenham(
        BitMap& bitMap,
        std::pair<float, float> onePoint,
        std::pair<float, float> twoPoint
    );
};