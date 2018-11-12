#include "Video.h"
#include "VideoTodoBasics.h"

/// Remove a sequence of frames you don't want to show in the video.
/// e.g. video.remove(2, 3) will remove the 3rd, 4rd, 5th frames
///
/// \param startPos is the position of first frame to be removed
/// \param length is the number of frames to be removed

// TODO: implement the remove function, go to Video.h to find its declaration
// Note: in implementation, you should check the range of first and last to avoid undefined behavior
// 1. if start position > position of last frame of video: no frame shall be removed
//    e.g. videoOf5Frame.remove(7, 10)
// 2. if position of the last frame to be remove > position of the last frame of video, remove frames
//    from startPos to the end of the video
//    e.g. videoHas5Frame.remove(2, 4) == videoHas5Frame.remove(2, 3) == video that contains first 2 frames

template<typename Frame>

void Video<Frame>::remove(unsigned long startPos, unsigned long length){
	if(startPos>(this->frames.size()-1)){
			return ;
		}
	 iterator p = this->frames.begin();

	    for(int i=0;i<startPos;i++){
	    	++p;
	    }

	    iterator q =p;

	    for (int i=0;i<length;i++){
	    	++q;
	    	if (q == frames.end()){
	    		--q;
	    		break;
	    	}
	    }

	    frames.erase(p,q);


}





