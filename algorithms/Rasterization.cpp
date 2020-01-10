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

/**
 * Алгоритм Брезенхэма
 **/
void Rasterization::bresenham(
    BitMap& bitMap,
    std::pair<float, float> onePoint,
    std::pair<float, float> twoPoint
)
{
    int XStart = onePoint.first;
    int YStart = onePoint.second;
    int XEnd   = twoPoint.first;
    int YEnd   = twoPoint.second;

    const int deltaX = std::abs(XEnd - XStart);
    const int deltaY = std::abs(YEnd - YStart);
    const int8_t signX = XStart < XEnd ? 1 : -1;
    const int8_t signY = YStart < YEnd ? 1 : -1;

    int error = deltaX - deltaY;
    bitMap.putPixel(XEnd, YEnd);

    while(XStart != XEnd || YStart != YEnd) 
    {
        bitMap.putPixel(XStart, YStart);
        const int errorTwo = error * 2;
        if(errorTwo > -deltaY) 
        {
            error -= deltaY;
            XStart += signX;
        }
        if(errorTwo < deltaX) 
        {
            error += deltaX;
            YStart += signY;
        }
    } 
}