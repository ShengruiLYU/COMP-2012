#include "Video.h"
#include "VideoTodoInsertion.h"
#include "Utilities.h"

int main() {
    Video< Image<char> > video(5, 5, 1);

    video << (Image<char>(5, 5, Utilities::PIXELS_2))
          << (Image<char>(5, 5, Utilities::PIXELS_0))
          << (Image<char>(5, 5, Utilities::PIXELS_1))
          << (Image<char>(5, 5, Utilities::PIXELS_2));

    Utilities::printCharVideo(video);
}
