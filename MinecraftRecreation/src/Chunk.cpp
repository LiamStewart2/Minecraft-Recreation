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
				if (y < 15 || y > 30)
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
					chunkMesh.loadMeshData(&vertices, glm::vec3(x, y, z));

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