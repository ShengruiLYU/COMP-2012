#include <iostream>
#include "Image.h"
#include "Utilities.h"

int main() {
    Image<char> image2012 = Image<char>(25, 7, Utilities::PIXELS_2012);
    std::vector< Image<char> > frames;
    frames.reserve(19);

    frames.push_back(image2012);
    for (int i = 0; i < 18; i++) {
        image2012.moveRight(1, ' ');
        frames.push_back(image2012);
    }
    Utilities::printCharVideo(frames, 4);

    return 0;
}
