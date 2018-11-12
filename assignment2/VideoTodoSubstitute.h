#include "Video.h"
#include "VideoTodoBasics.h"
#include <iostream>
using namespace std;

/// Substitute an individual frame at some position with another frame, this is useful for editing the scene in video
/// it is similar to array[x] = y;

// TODO: implement the substitute function, go to Video.h to find its declaration
// Please check if position is out of range of the video
// e.g. call substitute(10, someImage) on a video of 5 frames
// (You can also check if the width and height of this frame match the width and height of the video
//  e.g. use a 1920 x 1080 frame in 1280 × 720 video. But it is not required in this assignment)
//
// For simplicity, if the input is illegal, just skip and do nothing

template<typename Frame>
 void Video<Frame>::substitute(unsigned long position, const Frame& newFrame){
	if (position > frames.size()-1){
		return;
	}
	iterator p = frames.begin();


		 for(int i=0;i<position;i++){
		    	++p;

		 }

   p=frames.erase(p);





   frames.insert(p,newFrame);



}




