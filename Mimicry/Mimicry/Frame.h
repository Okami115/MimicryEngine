#pragma once
#include "../src/Engine/Exports.h"
#include "../Mimicry/Utility.h";

class MimicryEngine_API Frame
{
private:
	UV uv[4];
public:
	Frame();
	Frame(UV uv0, UV uv1, UV uv2, UV uv3);
	~Frame();
	UV* GetUV();
};

