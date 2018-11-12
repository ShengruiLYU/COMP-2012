#include "Video.h"
#include "VideoTodoAddAssign.h"
#include "Utilities.h"

int main() {

    // video1 is a video showing 2 0 1 2, in 4 seconds
    Video< Image<char> > video1(5, 5, 1);
    video1.append(Image<char>(5, 5, Utilities::PIXELS_2));
    video1.append(Image<char>(5, 5, Utilities::PIXELS_0));
    video1.append(Image<char>(5, 5, Utilities::PIXELS_1));
    video1.append(Image<char>(5, 5, Utilities::PIXELS_2));

    // video2 is a video showing 2 0 1 7, in 4 seconds
    Video< Image<char> > video2(5, 5, 1);
    video2.append(Image<char>(5, 5, Utilities::PIXELS_2));
    video2.append(Image<char>(5, 5, Utilities::PIXELS_0));
    video2.append(Image<char>(5, 5, Utilities::PIXELS_1));
    video2.append(Image<char>(5, 5, Utilities::PIXELS_7));

    // the modified video shows 2 0 1 2 2 0 1 7, in 8 seconds
    video1 += video2; // <----- the operator to implement in your task
    Utilities::printCharVideo(video1);

    return 0;
}
