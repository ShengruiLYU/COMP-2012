#ifndef VIDEOEDITOR_VIDEO_H
#define VIDEOEDITOR_VIDEO_H

#include <list>
#include "Image.h"

/// A data structure containing a video file
///
/// This is a simple video file represented as a sequence of frames. When the video is played,
/// the frames are read and display on screen with high frame rate, so the motions in images
/// looks smooth, see https://en.wikipedia.org/wiki/Sallie_Gardner_at_a_Gallop
///
/// \tparam Frame: the data type representing a frame, e.g. Image<char>, Image<int>
template <typename Frame>
class Video {
public:
    /// Use typedef to define a shortcut for std::list<T>::iterator, this allow operations similar in STL
    ///
    /// Note: here we have a special "typename" keyword (usually we use "typedef A B" without this "typename")
    /// It's OK if you do not understand it, just use iterator as normal type in your implementation.
    ///
    /// But if you are interested in it, you can read the explanation:
    /// http://en.cppreference.com/w/cpp/language/dependent_name#The_typename_disambiguator_for_dependent_names
    typedef typename std::list<Frame>::iterator iterator;
    typedef typename std::list<Frame>::const_iterator const_iterator;

    /// Create an empty video that contains nothing
    Video(unsigned long width, unsigned long height, float frameRate);

    /// Create a video by copying frame from another video
    Video(const Video& video);

    /// Assignment operator
    Video& operator=(const Video& video);

    unsigned long getWidth() const { return width; }

    unsigned long getHeight() const { return height; }

    float getFrameRate() const { return frameRate; }

    /// Similar to list.begin(), you can use it to access frames
    const_iterator begin() const { return frames.begin(); }
    iterator begin() { return frames.begin(); }

    /// Similar to list.end()
    const_iterator end() const { return frames.end(); }
    iterator end() { return frames.end(); }

    /// Append a new frame at the end of the video
    void append(const Frame& newFrame);

    /// Substitute an individual frame at some position with another frame,
    /// this is useful for editing the scene in video
    ///
    /// \param position where you want to edit
    /// \param newFrame that replace the old one in the video
    void substitute(unsigned long position, const Frame& newFrame);

    /// Reverse the video by reversing the order of frames, so that the frames are play from last to first
    /// e.g video of sunrise become video of sunset after reverse()
    void reverse();

    /// Concatenate two videos, so that the second video will be played immediately after the first video
    /// the length of the the returned video is the sum of lengths of two videos
    /// e.g. <video of lecture 1> + <video of lecture 2> + ... + <video of last lecture> = <video of this course>
    /// usage: videoX = videoY + videoZ
    Video operator+(const Video& nextVideo) const;

    /// Similar to operator+ while this operator append the next video to myself
    /// usage: videoX += videoY
    Video& operator+=(const Video& nextVideo);

    /// Create a new video, containing a sequence of frames copied from this video.
    /// e.g. video.extract(2, 3) will copy the 3 frames (3rd, 4rd, 5th)
    ///
    /// \param startPos is the position of first frame to be removed
    /// \param length is the number of frames to be removed
    Video extract(unsigned long startPos, unsigned long length) const;

    /// Remove a sequence of frames you don't want to show in the video.
    /// e.g. video.remove(2, 3) will remove the 3rd, 4rd, 5th frames
    ///
    /// \param startPos is the position of first frame to be removed
    /// \param length is the number of frames to be removed
    void remove(unsigned long startPos, unsigned long length);

private:
    unsigned long width, height;

    /// frameRate = the average number of frames displayed in 1 seconds. frameRate should be > 0
    /// The interval between frames = 1/frameRate seconds
    float frameRate;

    // We use list in video because video is played sequentially and we will perform lots of insertion and deletion
    std::list<Frame> frames;
};

#endif //VIDEOEDITOR_VIDEO_H
