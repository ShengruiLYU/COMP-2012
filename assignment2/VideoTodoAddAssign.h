#include "Video.h"
#include "VideoTodoBasics.h"

/// Similar to operator+ while this operator append the next video to myself
/// usage: videoX += videoY

// TODO: implement operator += here, go to Video.h and find its declaration
// Note: in this assignment, you are not required to check the width, height and frameRate of videos


template<typename Frame>
Video<Frame>& Video<Frame>::operator+=(const Video& nextVideo){

	const_iterator p = frames.begin();
	const_iterator q = nextVideo.frames.begin();
	Video<Frame> sum(this->width,this->height,this->frameRate);
	while(p != frames.end()){

		sum.frames.push_back(*p);
		++p;
	}

	while(q != nextVideo.frames.end()){
		sum.frames.push_back(*q);
		++q;
	}




	//*this =(*this)+nextVideo;
	*this = sum;
	return (*this);
}





