#pragma once
#include "../src/Engine/Exports.h"
#include <iostream>

struct MimicryEngine_API vec3
{
	float x;
	float y;
	float z;
};

struct MimicryEngine_API UV
{
	float U;
	float V;
	UV(float U, float V);
};

class MimicryEngine_API Utility
{


public:

	static std::string ReadShader(std::string Path);
	void ShaderStart();
	static std::string GetTextureVertexShaderPath();
	static std::string GetTextureFragmentShaderPath();



};

