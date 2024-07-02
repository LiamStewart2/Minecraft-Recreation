#pragma once

#include <string>

#include "Vertex.h"

class BlockType
{
public:
	BlockType(std::string blockName, bool isAir) : name(blockName), topTexture(glm::vec2(0, 0)), bottomTexture(glm::vec2(0, 0)), sideTexture(glm::vec2(0, 0)), air(isAir) {}
	BlockType(std::string blockName, glm::vec2 textureOffset) : name(blockName), topTexture(textureOffset), sideTexture(textureOffset), bottomTexture(textureOffset) {}
	BlockType(std::string blockName, glm::vec2 topTextureOffset, glm::vec2 textureOffset) : name(blockName), topTexture(topTextureOffset), sideTexture(textureOffset), bottomTexture(textureOffset) {}
	BlockType(std::string blockName, glm::vec2 topTextureOffset, glm::vec2 bottomTextureOffset, glm::vec2 textureOffset) : name(blockName), topTexture(topTextureOffset), sideTexture(textureOffset), bottomTexture(bottomTextureOffset) {}

	std::string name;

	bool air = false;

	glm::vec2 topTexture;
	glm::vec2 sideTexture;
	glm::vec2 bottomTexture;
};

