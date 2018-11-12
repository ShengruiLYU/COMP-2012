#ifndef VIDEOEDITOR_UTILITIES_H
#define VIDEOEDITOR_UTILITIES_H

#include "Image.h"
#include "Video.h"
#include <vector>

class Utilities {
public:
    static const char PIXELS_2012[25 * 7];
    static const char PIXELS_0[5 * 5];
    static const char PIXELS_1[5 * 5];
    static const char PIXELS_2[5 * 5];
    static const char PIXELS_7[5 * 5];

    static void printCharImage(const Image<char>& image);

    static void printCharVideo(const std::vector< Image<char> >& frames, float frameRate);

    /// Play the video by printing frame one by one, with a given frame rate.
    static void printCharVideo(const Video< Image<char> >& video);
};

#endif //VIDEOEDITOR_UTILITIES_H
