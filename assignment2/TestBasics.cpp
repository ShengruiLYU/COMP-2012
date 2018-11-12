#include "Video.h"
#include "VideoTodoBasics.h"
#include "Utilities.h"

int main() {
    Video< Image<char> > video1(5, 5, 1);
    video1.append(Image<char>(5, 5, Utilities::PIXELS_2));
    video1.append(Image<char>(5, 5, Utilities::PIXELS_0));
    video1.append(Image<char>(5, 5, Utilities::PIXELS_1));

    Video< Image<char> > video2(video1);
    video2.append(Image<char>(5, 5, Utilities::PIXELS_2));

    Utilities::printCharVideo(video2);

    return 0;
}
