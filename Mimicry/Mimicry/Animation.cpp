#include "Animation.h"


Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::AddFrame(UV uv, int width, int height)
{
	Frame* newFrame = new Frame(uv, 
		UV(uv.U + width, uv.V),
		UV(uv.U, uv.V + height),
		UV(uv.U + width, uv.V + height));

	frames.push_back(*newFrame);
	delete newFrame;
}
