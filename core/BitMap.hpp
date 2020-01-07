#pragma once

#include <iostream>
#include <vector>

class BitMap
{
private:
    size_t width;
    size_t height;

    std::vector<std::vector<int>> bitMap;
public:
    BitMap(size_t width, size_t height);

    void putPixel(size_t x, size_t y);
    void draw();
};