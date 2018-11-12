#include "Video.h"
#include "VideoTodoRemove.h"
#include "Utilities.h"

int main() {
    Image<char> image2012 = Image<char>(25, 7, Utilities::PIXELS_2012);
    Video< Image<char> > video(25, 7, 4);

    // The animation looks like a number 2012 moving to the right, the last frame's index is frame #18
    video.append(image2012);
    for (int i = 0; i < 18; i++) {
        image2012.moveRight(1, ' ');
        video.append(image2012);
    }

    // To the test remove function, we remove frames #7 to #12 (inclusive) from the video
    // Then in the animation, the displayed characters suddenly jump from 201 to 20
    // the last frame's index is frame #12 (was #18), i.e. 6 frames has been removed
    video.remove(7, 6); // <------ the function you need to implement

    Utilities::printCharVideo(video);

    return 0;
}
