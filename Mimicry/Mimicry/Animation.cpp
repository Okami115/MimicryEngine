#include "Animation.h"


Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::AddFrame(UV uv1, UV uv2, UV uv3, UV uv4)
{
	Frame newFrame = Frame(uv1, uv2, uv3, uv4);
	frames.push_back(newFrame);
}

float* Animation::PlayAnimation()
{
	float vertex[]
	{
		// X,	 Y,	   Z,	 R,    G,	 B,	   A,	 U,    V,
		0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, currentFrame.GetUV(0).U, currentFrame.GetUV(0).V, //Top Derecha
		0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, currentFrame.GetUV(1).U, currentFrame.GetUV(1).V,//Bot Derecha
		-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, currentFrame.GetUV(2).U, currentFrame.GetUV(2).V,//Bot Izquierda	
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, currentFrame.GetUV(3).U, currentFrame.GetUV(3).V,// Top Izquierda
	};

	return vertex;
}
