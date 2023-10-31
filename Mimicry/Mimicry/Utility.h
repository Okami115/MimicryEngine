#pragma once
#include "../src/Engine/Exports.h"
#include <iostream>

class MimicryEngine_API Utility
{


public:
	
	static std::string ReadShader(std::string Path);
	void ShaderStart();
	static std::string GetTextureVertexShaderPath();
	static std::string GetTextureFragmentShaderPath();

	struct vec3
	{
		float x;
		float y;
		float z;
	};

};

