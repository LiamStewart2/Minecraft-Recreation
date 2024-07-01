#include "Chunk.h"

Chunk::Chunk()
{
}

Chunk::~Chunk()
{
}

void Chunk::generateTerrain()
{
	for (int x = 0; x < config::chunkWidth; x++)
	{
		for (int z = 0; z < config::chunkHeight; z++)
		{
			for (int y = 0; y < config::chunkLayers; y++)
			{
				int index = getIndexFromRelativePosition(x, y, z);
				if (y > x + z)
					blockBuffer[index] = Grass;
				else
					blockBuffer[index] = Air;
			}
		}
	}
}

void Chunk::generateChunkMesh()
{
	double t = glfwGetTime();
	chunkMesh.setPosition(0, -10, 0);
	for (int x = 0; x < config::chunkWidth; x++)
	{
		for (int z = 0; z < config::chunkHeight; z++)
		{
			for (int y = 0; y < config::chunkLayers; y++)
			{
				int index = getIndexFromRelativePosition(x, y, z);
				
				if (blockBuffer[index] == Grass)
				{
					if (y < config::chunkLayers - 1 && blockBuffer[getIndexFromRelativePosition(x, y + 1, z)] == Air)
						chunkMesh.loadMeshData(&FaceData::TOP, glm::vec3(x, y, z));
					if (y > 0 && blockBuffer[getIndexFromRelativePosition(x, y - 1, z)] == Air)
						chunkMesh.loadMeshData(&FaceData::BOTTOM, glm::vec3(x, y, z));

					if (x < config::chunkWidth - 1 && blockBuffer[getIndexFromRelativePosition(x + 1, y, z)] == Air)
						chunkMesh.loadMeshData(&FaceData::RIGHT, glm::vec3(x, y, z));
					if (x > 0 && blockBuffer[getIndexFromRelativePosition(x - 1, y, z)] == Air)
						chunkMesh.loadMeshData(&FaceData::LEFT, glm::vec3(x, y, z));

					if (z < config::chunkHeight - 1 && blockBuffer[getIndexFromRelativePosition(x, y, z + 1)] == Air)
						chunkMesh.loadMeshData(&FaceData::BACK, glm::vec3(x, y, z));
					if (z > 0 && blockBuffer[getIndexFromRelativePosition(x, y, z - 1)] == Air)
						chunkMesh.loadMeshData(&FaceData::FRONT, glm::vec3(x, y, z));
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