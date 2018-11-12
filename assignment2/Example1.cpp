#include <iostream>
#include "Image.h"
#include "Utilities.h"

using std::cout;
using std::endl;

int main() {
    // 2
    const char pixelsTwo[5 * 5] = {
            '#', '#', '#', '#', '#',
            ' ', ' ', ' ', ' ', '#',
            '#', '#', '#', '#', '#',
            '#', ' ', ' ', ' ', ' ',
            '#', '#', '#', '#', '#',
    };

    const Image<char> imageTwo = Image<char>(5, 5, pixelsTwo);
    cout << "Below is an Image<char> showing the number 2, it's (width, height) is 5 x 5:" << endl;
    Utilities::printCharImage(imageTwo);

    // 3
    const char pixelsThree[5 * 5] = {
            '@', '@', '@', '@', '@',
            ' ', ' ', ' ', ' ', '@',
            '@', '@', '@', '@', '@',
            ' ', ' ', ' ', ' ', '@',
            '@', '@', '@', '@', '@',
    };
    const Image<char> imageThree = Image<char>(5, 5, pixelsThree);
    cout << "This is an Image<char> showing the number 3, we changed the character # to @:" << endl;
    Utilities::printCharImage(imageThree);

    // 4
    const char pixelsFour[5 * 5] = {
            'k', ' ', ' ', ' ', 'I',
            '7', ' ', ' ', ' ', '=',
            't', '#', '4', '~', 'n',
            ' ', ' ', ' ', ' ', '?',
            ' ', ' ', ' ', ' ', 'Y',
    };
    const Image<char> imageFour = Image<char>(5, 5, pixelsFour);
    cout << "An Image<char> showing the number 4 (we can use any character):" << endl;
    Utilities::printCharImage(imageFour);


    // H
    cout << "Let's copy the image 4 to a new image." << endl;
    Image<char> imageH = Image<char>(imageFour);

    cout << "Then modify the pixels (3, 0) and (4, 0) of the new image to '+' using operator()" << endl;
    imageH(3, 0) = '+';
    imageH(4, 0) = '+';
    cout << "Now it looks like H:" << endl;
    Utilities::printCharImage(imageH);

    cout << "What are the width and height of this image?" << endl
         << "Answer: width=" << imageH.getWidth() << ", height=" << imageH.getHeight() << endl;

    // <- H
    Image<char> imageHLeft = Image<char>(imageH);
    imageHLeft.moveLeft(1, ' ');
    cout << endl << "If we move this image to left by 1 pixel, the leftmost column disappeared" << endl;
    Utilities::printCharImage(imageHLeft);

    // -> H
    Image<char> imageHRight = Image<char>(imageH);
    imageHRight.moveRight(1, ' ');
    cout << "If we move this image to right by 1 pixel, the rightmost column disappeared" << endl;
    Utilities::printCharImage(imageHRight);

    return 0;
}
