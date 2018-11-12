#include "Video.h"
#include "VideoTodoExtract.h"
#include "Utilities.h"

int main() {
    Image<char> image2012 = Image<char>(25, 7, Utilities::PIXELS_2012);
    Video< Image<char> > video(25, 7, 4);

    // The animation looks like a number 2012 moving to the right
    video.append(image2012);
    for (int i = 0; i < 18; i++) {
        image2012.moveRight(1, ' ');
        video.append(image2012);
    }

    Video< Image<char> > part = video.extract(6, 7); // <----- the function you should implement

    Utilities::printCharVideo(part);
    return 0;
}
