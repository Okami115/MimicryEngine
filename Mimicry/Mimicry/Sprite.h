#pragma once
#include "Engine/Entities/Entity2D.h"
#include "Animation.h"
#include "../src/Engine/Exports.h"
#include "../Mimicry/Texture.h"
#include <iostream>

class MimicryEngine_API Sprite : public Entity2D
{
private:
	Texture* texture;
	
	Animation* animation;

	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scl;
	glm::vec3 color;

public:
	Sprite(Renderer* renderer);
	Sprite();
	~Sprite();
	void Draw2D() override;

	void SetSprite(std::string path);

};

