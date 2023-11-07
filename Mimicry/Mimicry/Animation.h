#pragma once
#include "../src/Engine/Exports.h"
#include "Frame.h"
#include <vector>

class MimicryEngine_API Animation
{
private:
	Frame currentFrame;
	std::vector<Frame> frames;

public:
	Animation();
	~Animation();
	void AddFrame(UV uv, int width, int height);

};

