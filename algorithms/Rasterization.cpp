#include "Rasterization.hpp"

/**
 * Алгоритм DDA-Line
 **/
void Rasterization::DDALine(
    BitMap& bitMap,
    std::pair<float, float> onePoint,
    std::pair<float, float> twoPoint
)
{
    const int XStart = onePoint.first;
    const int YStart = onePoint.second;
    const int XEnd   = twoPoint.first;
    const int YEnd   = twoPoint.second;

    int LStep = std::max(
        std::abs(XEnd - XStart), 
        std::abs(YEnd - YStart)
    );

    float x = onePoint.first;
    float y = onePoint.second;

    float dX = (XEnd - XStart) / LStep;
    float dY = (YEnd - YStart) / LStep;

    while(LStep)
    {
        bitMap.putPixel(x, y);
        x += dX;
        y += dY;

        LStep--;
    } 
}