#include "Scene.h"

void Scene::initChunkMap(glm::vec2 size, TextureAtlas* textureAtlas)
{
	chunkMap.clear();

	for (int i = -size.x / 2; i <= size.x / 2; i++)
	{
		for (int j = -size.y / 2; j < size.y / 2; j++)
		{
			Chunk* newChunk = new Chunk(glm::vec2(i, j));

			newChunk->generateTerrain();
			newChunk->generateChunkMesh(textureAtlas);

			chunkMap.push_back(newChunk);
		}
	}
}

void Scene::renderScene(Renderer* renderer, Camera* camera)
{
	for(Chunk* chunk : chunkMap)
		renderer->render(camera, chunk->getChunkMesh());
}

// Will return null position is invalid or isnt loaded
Chunk* Scene::getChunk(glm::vec2 chunkPosition)
{
	for (Chunk* chunk : chunkMap)
	{
		if(chunk->getWorldPosition() == chunkPosition)
			return chunk;
	}
	return nullptr;
}