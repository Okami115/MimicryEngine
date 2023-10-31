#pragma once
#include <iostream>
#include "../src/Engine/Exports.h"
class MimicryEngine_API TextureImporter
{
public:
	static bool LoadTexture(const std::string &path, unsigned int &texture, int &width, int &height, int &channels);
};

