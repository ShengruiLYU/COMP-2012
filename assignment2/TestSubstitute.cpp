#include "Video.h"
#include "VideoTodoSubstitute.h"
#include "Utilities.h"

int main() {

    // video1 is a video showing 2 0 1 2, in 4 seconds
    Video< Image<char> > video(5, 5, 1);
    video.append(Image<char>(5, 5, Utilities::PIXELS_2));
    video.append(Image<char>(5, 5, Utilities::PIXELS_0));
    video.append(Image<char>(5, 5, Utilities::PIXELS_1));
    video.append(Image<char>(5, 5, Utilities::PIXELS_2));

    // Create a image showing number 7
    Image<char> image7 = Image<char>(5, 5, Utilities::PIXELS_7);

    // Replace the frame at position 3 (the last frame) of the image, the video become 2017
    video.substitute(3, image7); // <----- the operator to implement

    Utilities::printCharVideo(video);

    return 0;
}
