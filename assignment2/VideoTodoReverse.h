#include "Video.h"
#include "VideoTodoBasics.h"

/// Reverse the video by reversing the order of frames, so that the frames are play from last to first
/// e.g video of sunrise become video of sunset after reverse()

// TODO: implement the member function reverse()
template <typename Frame>
void Video<Frame>::reverse()
{
int size = frames.size();
std::list<Frame> Rframes;

for (int i=0 ;i<size;i++){
	Frame temp = frames.front();
	frames.pop_front();
	Rframes.push_front(temp);
}

frames=Rframes;



}
