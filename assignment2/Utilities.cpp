#include "Utilities.h"
#include <iostream>

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

using std::cout;
using std::endl;

namespace VideoEditor {
    /// Pause the program and wake up in a certain time interval
    void sleep(unsigned int milliseconds) {
#ifdef WIN32
        Sleep(milliseconds);
#else
        usleep(milliseconds * 1000);
#endif // win32
    }
}

const char Utilities::PIXELS_2012[25 * 7] = {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', '2', '2', '2', '2', '2', ' ', '0', '0', '0', '0', '0', ' ', ' ', '1', '1', '1', ' ', ' ', '2', '2', '2', '2', '2', ' ',
        ' ', ' ', ' ', ' ', ' ', '2', ' ', '0', ' ', ' ', ' ', '0', ' ', ' ', '1', '1', '1', ' ', ' ', ' ', ' ', ' ', ' ', '2', ' ',
        ' ', '2', '2', '2', '2', '2', ' ', '0', ' ', ' ', ' ', '0', ' ', ' ', '1', '1', '1', ' ', ' ', '2', '2', '2', '2', '2', ' ',
        ' ', '2', ' ', ' ', ' ', ' ', ' ', '0', ' ', ' ', ' ', '0', ' ', ' ', '1', '1', '1', ' ', ' ', '2', ' ', ' ', ' ', ' ', ' ',
        ' ', '2', '2', '2', '2', '2', ' ', '0', '0', '0', '0', '0', ' ', ' ', '1', '1', '1', ' ', ' ', '2', '2', '2', '2', '2', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
};

const char Utilities::PIXELS_0[5 * 5] = {
        '0', '0', '0', '0', '0',
        '0', ' ', ' ', ' ', '0',
        '0', ' ', ' ', ' ', '0',
        '0', ' ', ' ', ' ', '0',
        '0', '0', '0', '0', '0',
};

const char Utilities::PIXELS_1[5 * 5] = {
        ' ', '1', '1', '1', ' ',
        ' ', '1', '1', '1', ' ',
        ' ', '1', '1', '1', ' ',
        ' ', '1', '1', '1', ' ',
        ' ', '1', '1', '1', ' ',
};

const char Utilities::PIXELS_2[5 * 5] = {
        '2', '2', '2', '2', '2',
        ' ', ' ', ' ', ' ', '2',
        '2', '2', '2', '2', '2',
        '2', ' ', ' ', ' ', ' ',
        '2', '2', '2', '2', '2',
};

const char Utilities::PIXELS_7[5 * 5] = {
        '7', '7', '7', '7', '7',
        ' ', ' ', ' ', ' ', '7',
        ' ', ' ', ' ', ' ', '7',
        ' ', ' ', ' ', ' ', '7',
        ' ', ' ', ' ', ' ', '7',
};

void Utilities::printCharImage(const Image<char>& image)
{
    for (unsigned long row = 0; row < image.getHeight(); row++) {
        for (unsigned long col = 0; col < image.getWidth(); col++) {
            cout << image(row, col);
        }
        cout << std::endl;
    }
}

void Utilities::printCharVideo(const std::vector< Image<char> >& frames, float frameRate)
{
    if (frameRate < 0.001) {
        return;
    }

    unsigned int intervalMs = static_cast<unsigned int>(1000.0 / frameRate);
    int frameId = 0;
    for (std::vector< Image<char> >::const_iterator it = frames.begin(); it != frames.end(); it++) {
        cout << "Frame #" << frameId << ":" << endl;
        printCharImage(*it);
        VideoEditor::sleep(intervalMs);
        frameId++;
    }
}

void Utilities::printCharVideo(const Video< Image<char> >& video)
{
    float frameRate = video.getFrameRate();
    if (frameRate < 0.001) {
        return;
    }

    unsigned int intervalMs = static_cast<unsigned int>(1000.0 / frameRate);

    int frameId = 0;
    for (Video< Image<char> >::const_iterator it = video.begin(); it != video.end(); it++) {
        cout << "Frame #" << frameId << ":" << endl;
        printCharImage(*it);
        VideoEditor::sleep(intervalMs);
        frameId++;
    }
}
