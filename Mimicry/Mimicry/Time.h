#pragma once
#include "../src/Engine/Exports.h"

static class MimicryEngine_API Time
{

public:
	static double oldTime;
	static float timeSinceStart;

	static float DeltaTime();
	static float getTime();
};

