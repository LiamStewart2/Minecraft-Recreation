#include "Chunk.h"

#include "Scene.h"

Chunk::~Chunk()
{
	chunkMesh.clean();
}

void Chunk::generateTerrain()
{
	for (int x = 0; x < config::chunkWidth; x++)
	{
		for (int z = 0; z < config::chunkHeight; z++)
		{
			glm::vec3 blockWorldPosition = getBlockWorldPosition(glm::vec3(x, 0, z));
			float a = sin((blockWorldPosition.x * blockWorldPosition.z) * 0.1f);
			int height = a * 3 + 16;

			//int height = sin(x*2 * z+1 * 0.001f) * 5;

			for (int y = 0; y < config::chunkLayers; y++)
			{
				int index = getIndexFromRelativePosition(x, y, z);


				if (y == height)
					blockBuffer[index] = &BlockDatabase::Grass;
				else if(y < height)
					blockBuffer[index] = &BlockDatabase::Dirt;
				else
					blockBuffer[index] = &BlockDatabase::Air;
			}
		}
	}
}

void Chunk::generateChunkMesh(TextureAtlas* textureAtlas)
{
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
					if (y < config::chunkLayers - 1 && getBlockAtPosition(x, y + 1, z)->air)
						chunkMesh.loadMeshData(&FaceData::TOP, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->topTexture));
					if (y > 0 && getBlockAtPosition(x, y - 1, z)->air)
						chunkMesh.loadMeshData(&FaceData::BOTTOM, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->bottomTexture));

					if (x < config::chunkWidth - 1 && getBlockAtPosition(x + 1, y, z)->air)
						chunkMesh.loadMeshData(&FaceData::RIGHT, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));
					if (x > 0 && getBlockAtPosition(x - 1, y, z)->air)
						chunkMesh.loadMeshData(&FaceData::LEFT, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));

					if (z < config::chunkHeight - 1 && getBlockAtPosition(x, y, z + 1)->air)
						chunkMesh.loadMeshData(&FaceData::BACK, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));
					if (z > 0 && getBlockAtPosition(x, y, z - 1)->air)
						chunkMesh.loadMeshData(&FaceData::FRONT, glm::vec3(x, y, z), textureAtlas->getTextureCoordinateOffset(currentBlock->sideTexture));
				}

			}
		}
	}
}

void Chunk::updateChunkMeshBuffers()
{
	chunkMesh.generateMeshBuffers();
}

BlockType* Chunk::getBlockAtPosition(int x, int y, int z)
{
	return blockBuffer[getIndexFromRelativePosition(x, y, z)];
}

int Chunk::getIndexFromRelativePosition(int x, int y, int z)
{
	int index = (y * config::chunkWidth * config::chunkHeight) + (z * config::chunkHeight) + x;
	return index;
}

glm::vec3 Chunk::getBlockWorldPosition(glm::vec3 relativeBlockPosition)
{
	int xPosition = chunkWorldPosition.x * config::chunkWidth + relativeBlockPosition.x;
	int zPosition = chunkWorldPosition.y * config::chunkHeight + relativeBlockPosition.z;
	return glm::vec3(xPosition, relativeBlockPosition.y, zPosition);
}