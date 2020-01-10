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

    u_int LStep = std::max(
        std::abs(XEnd - XStart), 
        std::abs(YEnd - YStart)
    ) + 1;

    float x = onePoint.first;
    float y = onePoint.second;

    float dX = (float)(XEnd - XStart) / LStep;
    float dY = (float)(YEnd - YStart) / LStep;

    while(LStep)
    {
        bitMap.putPixel(x, y);
        x += dX;
        y += dY;

        LStep--;
    } 
}