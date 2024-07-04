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

	void update(Camera* camera);
	void renderScene(Renderer* renderer, Camera* camera);

	Chunk* getChunk(glm::vec2 chunkPosition);
private:
	TextureAtlas* texture;

	std::vector<Chunk*> chunkMap;
	glm::vec2 lastCameraChunkPos = glm::vec2(0,0);

	glm::vec2 generateChunkPosition(glm::vec2 direction, int chunkIndex, glm::vec2 cameraChunkPos);

	void updateAllChunkEdges();
	void updateChunkEdges(Chunk* chunk);

	void dynamicChunkLoading(Camera* camera);
};