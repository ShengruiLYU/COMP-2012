/// This file defines the basic functions of Image class.
/// We put the implementations here to make the header file cleaner.

#include "Image.h"
#include <algorithm>

template <typename PixelType>
Image<PixelType>::Image(unsigned long width, unsigned long height, const PixelType pixels[])
        : width(width), height(height), pixels(pixels, pixels + width * height)
{

}

template <typename PixelType>
Image<PixelType>::Image(unsigned long width, unsigned long height, const std::vector<PixelType>& pixels)
        : width(width), height(height), pixels(pixels)
{

}

template <typename PixelType>
Image<PixelType>::Image(const Image<PixelType>& image)
        : width(image.width), height(image.height), pixels(image.pixels)
{

}

template <typename PixelType>
Image<PixelType>& Image<PixelType>::operator=(const Image& image)
{
    if (this != &image) { // check self-assignment
        width = image.width;
        height = image.height;
        pixels = std::vector<PixelType>(image.pixels);
    }

    return *this;
}

template <typename PixelType>
unsigned long Image<PixelType>::getWidth() const
{
    return width;
}

template <typename PixelType>
unsigned long Image<PixelType>::getHeight() const
{
    return height;
}

template <typename PixelType>
const PixelType& Image<PixelType>::operator()(unsigned long row, unsigned long column) const
{
    return pixels[row * width + column];
}

template <typename PixelType>
PixelType& Image<PixelType>::operator()(unsigned long row, unsigned long column)
{
    return pixels[row * width + column];
}

template <typename PixelType>
void Image<PixelType>::moveLeft(unsigned long distance, PixelType fillPixel)
{
    if (distance >= width) {
        std::fill(pixels.begin(), pixels.end(), fillPixel);
    } else {
        std::rotate(pixels.begin(), pixels.begin() + distance, pixels.end());
        for (unsigned long row = 0; row < height; row++) {
            for (unsigned long col = width-distance; col < width; col++) {
                pixels[row * width + col] = fillPixel;
            }
        }
    }
}

template <typename PixelType>
void Image<PixelType>::moveRight(unsigned long distance, PixelType fillPixel)
{
    if (distance >= width) {
        std::fill(pixels.begin(), pixels.end(), fillPixel);
    } else {
        std::rotate(pixels.rbegin(), pixels.rbegin() + distance, pixels.rend());
        for (unsigned long row = 0; row < height; row++) {
            for (unsigned long col = 0; col < distance; col++) {
                pixels[row * width + col] = fillPixel;
            }
        }
    }
}
