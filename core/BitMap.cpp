#include "BitMap.hpp"

BitMap::BitMap(size_t width, size_t height)
{
    this->width = width;
    this->height = height;

    for(int i = 0; i < height; i++)
    {
        this->bitMap.push_back(std::vector<int>(width));
        for(int j = 0; j < width; j++)
        {
            this->bitMap[i][j] = 0;
        }
    }
}

void BitMap::putPixel(size_t x, size_t y)
{
    this->bitMap[y - 1][x - 1] = 1;
}

void BitMap::draw()
{
    for(int i = 0; i < this->height; i++)
    {
        for(int j = 0; j < this->width; j++)
        {
            std::cout << this->bitMap[i][j];
        }
        std::cout << std::endl;
    }
}