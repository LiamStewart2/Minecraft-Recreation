#pragma once

#include "Mesh.h"
#include "config.h"
#include "FaceData.h"
#include "BlockDatabase.h"
#include "TextureAtlas.h"

enum Block { Air, Grass };

class Chunk
{
public:
	Chunk() {}
	Chunk(glm::vec2 chunkPosition) {chunkWorldPosition = chunkPosition;}
	~Chunk() {}

	void generateTerrain();
	void generateChunkMesh(TextureAtlas* textureAtlas);

	Mesh* getChunkMesh() { return &chunkMesh; }

	BlockType* getBlockAtPosition(int x, int y, int z);
	int getIndexFromRelativePosition(int x, int y, int z);

	glm::vec2 getWorldPosition() { return chunkWorldPosition; }
private:
	Mesh chunkMesh;
	glm::vec2 chunkWorldPosition = glm::vec2(0,0);

	BlockType* blockBuffer[config::chunkWidth * config::chunkHeight * config::chunkLayers];
};