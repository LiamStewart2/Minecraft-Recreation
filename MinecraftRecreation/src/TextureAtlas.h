#pragma once

#include "glm.hpp"

#include "Texture.h"
#include "BlockType.h"

class TextureAtlas : public Texture
{
public:
	void loadTextureAtlas(const char* textureFilePath, int columns, int rows);
	glm::vec2 getTextureCoordinateOffset(glm::vec2 texturePosition);
private:
	int Columns = 0; int Rows = 0;
	float xScale = 0.0f; float yScale = 0.0f;
};

