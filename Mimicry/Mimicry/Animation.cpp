#include "Animation.h"
#include "Time.h"


Animation::Animation()
{
}

Animation::Animation(float speed)
{
	this->speed = speed;
	timer = 0;
	index = 0;
}

Animation::~Animation()
{
}

void Animation::AddFrame(UV uv1, UV uv2, UV uv3, UV uv4)
{
	Frame newFrame = Frame(uv1, uv2, uv3, uv4);
	frames.push_back(newFrame);
	currentFrame = frames[0];
}

float* Animation::PlayAnimation()
{
	timer += Time::DeltaTime();
	if (timer > speed)
	{
		std::cout << "Change Frame" << std::endl;

		while (timer > speed)
		{
			timer -= speed;
			index++;

			if (index > frames.size() - 1)
				index = 0;
		}

		
	}

	currentFrame = frames[index];

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
