#pragma once

#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Chunk.h"
#include "Renderer.h"
#include "Camera.h"
#include "TextureAtlas.h"

class Scene
{
public:
	void initChunkMap(TextureAtlas* textureAtlas);

	void update(Camera* camera);
	void renderScene(Renderer* renderer, Camera* camera);

	void deleteAllChunks();
	
	Chunk* getChunk(glm::vec2 chunkPosition);
private:
	TextureAtlas* texture;

	std::vector<Chunk*> chunkMap;
	std::deque<glm::vec2> chunkGenerationQueue;

	glm::vec2 lastCameraChunkPos = glm::vec2(0,0);

	void updateAllChunkEdges();
	void updateChunkEdges(Chunk* chunk);

	void dynamicChunkLoading(Camera* camera);
	void chunkGenerationQueueManager();

	double chunkGenerationAllowance = (1.0f / 1000.0f) * 2.0f;
	void addChunkToGenerationQueue(glm::vec2 chunkPosition);
	void removeChunkFromGenerationQueue(glm::vec2 chunkPosition);
	bool isPositionInChunkGenerationQueue(glm::vec2 chunkPosition);
};