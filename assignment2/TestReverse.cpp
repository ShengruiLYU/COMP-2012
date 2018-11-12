#include "Video.h"
#include "VideoTodoReverse.h"
#include "Utilities.h"

int main() {
    // The original video contains 4 frame, showing 2 0 1 2
    // Your task is to implement reverse() function in VideoTodo.tpp
    // If your reverse if correct, the output will show 2 1 0 2

    Video< Image<char> > video(5, 5, 1);
    video.append(Image<char>(5, 5, Utilities::PIXELS_2));
    video.append(Image<char>(5, 5, Utilities::PIXELS_0));
    video.append(Image<char>(5, 5, Utilities::PIXELS_1));
    video.append(Image<char>(5, 5, Utilities::PIXELS_2));

    video.reverse(); // <--- this is the function you will implement in VideoTodo.tpp, it reverses the order of frames

    Utilities::printCharVideo(video);
    return 0;
}
