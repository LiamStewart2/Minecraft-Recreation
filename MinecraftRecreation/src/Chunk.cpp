#include "Chunk.h"

void Chunk::generateTerrain()
{
	for (int x = 0; x < config::chunkWidth; x++)
	{
		for (int z = 0; z < config::chunkHeight; z++)
		{
			for (int y = 0; y < config::chunkLayers; y++)
			{
				int index = getIndexFromRelativePosition(x, y, z);
				if (y < x + z + 2)
					blockBuffer[index] = &BlockDatabase::Grass;
				else if (y == 15)
					blockBuffer[index] = &BlockDatabase::Stone;
				else
					blockBuffer[index] = &BlockDatabase::Air;
			}
		}
	}
}

void Chunk::generateChunkMesh(TextureAtlas* textureAtlas)
{
	double t = glfwGetTime();

	chunkMesh.setPosition(chunkWorldPosition.x * config::chunkWidth, 0, chunkWorldPosition.y * config::chunkHeight);

	for (int x = 0; x < config::chunkWidth; x++)
	{
		for (int z = 0; z < config::chunkHeight; z++)
		{
			for (int y = 0; y < config::chunkLayers; y++)
			{
				int index = getIndexFromRelativePosition(x, y, z);
				BlockType* currentBlock = blockBuffer[index];

				if (currentBlock->air == false)
				{
					if (y < config::chunkLayers - 1 && blockBuffer[getIndexFromRelativePosition(x, y + 1, z)]->air)
						chunkMesh.loadMeshData(&FaceData::TOP, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->topTexture));
					if (y > 0 && blockBuffer[getIndexFromRelativePosition(x, y - 1, z)]->air)
						chunkMesh.loadMeshData(&FaceData::BOTTOM, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->bottomTexture));

					if (x < config::chunkWidth - 1 && blockBuffer[getIndexFromRelativePosition(x + 1, y, z)]->air)
						chunkMesh.loadMeshData(&FaceData::RIGHT, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));
					if (x > 0 && blockBuffer[getIndexFromRelativePosition(x - 1, y, z)]->air)
						chunkMesh.loadMeshData(&FaceData::LEFT, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));

					if (z < config::chunkHeight - 1 && blockBuffer[getIndexFromRelativePosition(x, y, z + 1)]->air)
						chunkMesh.loadMeshData(&FaceData::BACK, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));
					if (z > 0 && blockBuffer[getIndexFromRelativePosition(x, y, z - 1)]->air)
						chunkMesh.loadMeshData(&FaceData::FRONT, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));
				}

			}
		}
	}
	chunkMesh.generateMeshBuffers();
	std::cout << glfwGetTime() - t << ": Time to generate chunk" << std::endl;
}

Block Chunk::getBlockAtPosition(int x, int y, int z)
{
	return Block();
}

int Chunk::getIndexFromRelativePosition(int x, int y, int z)
{
	int index = (y * config::chunkWidth * config::chunkHeight) + (z * config::chunkHeight) + x;
	return index;
}