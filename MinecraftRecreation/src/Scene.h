#pragma once

#include <vector>

#include "Chunk.h"
#include "Renderer.h"
#include "Camera.h"
#include "TextureAtlas.h"

class Scene
{
public:
	void initChunkMap(glm::vec2 size, TextureAtlas* textureAtlas);
	void renderScene(Renderer* renderer, Camera* camera);

	Chunk* getChunk(glm::vec2 chunkPosition);
private:
	std::vector<Chunk*> chunkMap;
};