#include "Video.h"

// TODO: implement constructor for Video class, create empty video with given width, height, frameRate
template <typename Frame>
Video<Frame>::Video(unsigned long width, unsigned long height, float frameRate)
{

this->width =width;
this->height = height;
this->frameRate=frameRate;


}

// TODO: implement copy constructor for Video class, copy all properties and frames from another video object
template <typename Frame>
Video<Frame>::Video(const Video<Frame>& video)
{


*this = video;

}

// TODO: implement assignment operator
template <typename Frame>
Video<Frame>& Video<Frame>::operator=(const Video& video)
{
if(this != &video){
	this->width = video.width;
	this->height= video.height;
	this->frameRate=video.frameRate;
	this->frames=video.frames;

}

return *this;

}

// TODO: implement append function. It appends a new frame to the end of the list.
// Note: in this assignment, we do not require you to check width and height of the frame
template <typename Frame>
void Video<Frame>::append(const Frame& newFrame)
{

frames.push_back(newFrame);


}
