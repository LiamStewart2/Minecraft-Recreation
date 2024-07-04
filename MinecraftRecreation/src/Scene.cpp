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

	updateChunkEdges(textureAtlas);
}

void Scene::updateChunkEdges(TextureAtlas* textureAtlas)
{
    for (Chunk* chunk : chunkMap)
    {
        // Check y- axis -- north
        Chunk* northernChunk = getChunk(chunk->getWorldPosition() + glm::vec2(0, -1));
        if (northernChunk != nullptr)
        {
            for (int x = 0; x < config::chunkWidth; x++)
            {
                for (int y = 0; y < config::chunkLayers; y++)
                {
                    BlockType* currentBlock = chunk->getBlockAtPosition(x, y, 0); // Fixed height position
                    BlockType* northernBlock = northernChunk->getBlockAtPosition(x, y, config::chunkHeight - 1); // Fixed height position

                    if (currentBlock->air == false && northernBlock->air == true)
                    {
                        chunk->chunkMesh.loadMeshData(&FaceData::FRONT, glm::vec3(x, y, 0), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));
                    }
                }
            }
        }

        // Check y+ axis -- south
        Chunk* southernChunk = getChunk(chunk->getWorldPosition() + glm::vec2(0, 1));
        if (southernChunk != nullptr)
        {
            for (int x = 0; x < config::chunkWidth; x++)
            {
                for (int y = 0; y < config::chunkLayers; y++)
                {
                    BlockType* currentBlock = chunk->getBlockAtPosition(x, y, config::chunkHeight - 1); // Fixed height position
                    BlockType* southernBlock = southernChunk->getBlockAtPosition(x, y, 0); // Fixed height position

                    if (currentBlock->air == false && southernBlock->air == true)
                    {
                        chunk->chunkMesh.loadMeshData(&FaceData::BACK, glm::vec3(x, y, config::chunkHeight - 1), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));
                    }
                }
            }
        }

        // Check x- axis -- west
        Chunk* westernChunk = getChunk(chunk->getWorldPosition() + glm::vec2(-1, 0));
        if (westernChunk != nullptr)
        {
            for (int z = 0; z < config::chunkHeight; z++) // Fixed loop limit
            {
                for (int y = 0; y < config::chunkLayers; y++)
                {
                    BlockType* currentBlock = chunk->getBlockAtPosition(0, y, z); // Fixed x position
                    BlockType* westernBlock = westernChunk->getBlockAtPosition(config::chunkWidth - 1, y, z); // Fixed x position

                    if (currentBlock->air == false && westernBlock->air == true)
                    {
                        chunk->chunkMesh.loadMeshData(&FaceData::LEFT, glm::vec3(0, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture)); // Fixed position
                    }
                }
            }
        }

        // Check x+ axis -- east
        Chunk* easternChunk = getChunk(chunk->getWorldPosition() + glm::vec2(1, 0));
        if (easternChunk != nullptr)
        {
            for (int z = 0; z < config::chunkHeight; z++) // Fixed loop limit
            {
                for (int y = 0; y < config::chunkLayers; y++)
                {
                    BlockType* currentBlock = chunk->getBlockAtPosition(config::chunkWidth - 1, y, z); // Fixed x position
                    BlockType* easternBlock = easternChunk->getBlockAtPosition(0, y, z); // Fixed x position

                    if (currentBlock->air == false && easternBlock->air == true)
                    {
                        chunk->chunkMesh.loadMeshData(&FaceData::RIGHT, glm::vec3(config::chunkWidth - 1, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture)); // Fixed position
                    }
                }
            }
        }
        chunk->updateChunkMeshBuffers();
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