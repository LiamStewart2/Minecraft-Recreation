#pragma once

#include "Mesh.h"
#include "config.h"
#include "FaceData.h"

enum Block { Air, Grass };

class Chunk
{
public:
	Chunk();
	~Chunk();

	void generateTerrain();
	void generateChunkMesh();

	Mesh* getChunkMesh() { return &chunkMesh; }

	Block getBlockAtPosition(int x, int y, int z);
	int getIndexFromRelativePosition(int x, int y, int z);

private:
	Mesh chunkMesh;

	Block blockBuffer[config::chunkWidth * config::chunkHeight * config::chunkLayers];
};