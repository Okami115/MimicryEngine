#pragma once
#include "../src/Engine/Exports.h"
#include "Frame.h"
#include <vector>

class MimicryEngine_API Animation
{
private:
	Frame currentFrame;
	int currentFrameCounter;
	int maxFrameAnimation;
	std::vector<Frame> frames;
	float frameAnimation;
	float spriteWidth;
	float spriteHight;
	float frameWidth;
	float frameHight;
	int index;
	float timer;

public:
	Animation();
	Animation(float speed);
	~Animation();
	void AddFrame(UV uv1, UV uv2, UV uv3, UV uv4);
	float* PlayAnimation();

};

