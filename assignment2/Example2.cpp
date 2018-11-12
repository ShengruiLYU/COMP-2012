#include <iostream>
#include "Image.h"
#include "Utilities.h"

int main() {
    std::vector< Image<char> > frames;
    frames.reserve(4);

    frames.push_back(Image<char>(5, 5, Utilities::PIXELS_2));
    frames.push_back(Image<char>(5, 5, Utilities::PIXELS_0));
    frames.push_back(Image<char>(5, 5, Utilities::PIXELS_1));
    frames.push_back(Image<char>(5, 5, Utilities::PIXELS_2));

    Utilities::printCharVideo(frames, 1);

    return 0;
}
