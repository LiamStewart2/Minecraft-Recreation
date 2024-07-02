#include "TextureAtlas.h"

void TextureAtlas::loadTextureAtlas(const char* textureFilePath, int columns, int rows)
{
	loadTexture(textureFilePath);

	Columns = columns; Rows = rows;
	xScale = static_cast<float>(width) / Columns / width;
	yScale = static_cast<float>(height) / Rows / height;
}

glm::vec2 TextureAtlas::getTextureCoordinateOffset(glm::vec2 texturePosition)
{
	return texturePosition * glm::vec2(xScale, yScale);
}