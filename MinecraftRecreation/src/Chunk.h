#pragma once

#include "Mesh.h"
#include "config.h"
#include "FaceData.h"
#include "BlockDatabase.h"

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

	BlockType* blockBuffer[config::chunkWidth * config::chunkHeight * config::chunkLayers];
};