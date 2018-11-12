#include "Video.h"
#include "VideoTodoBasics.h"

/// Provide a more convenient way to append frames to video, using operator <<
/// For example, assume you have frameX, frameY, ... frameZ,
/// you can add these frame to end of video by calling
/// video << frameX << frameY << ... << frameZ
///
/// It should equivalent to
/// video.append(frameX);
/// video.append(frameY);
/// ...
/// video.append(frameZ);

// TODO: implement operator<<



template<typename Frame>
Video<Frame>& operator<<(Video<Frame>& video,const Frame& newFrame ) {

	video.append(newFrame);
	return video;
}





