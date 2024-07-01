#pragma once

#include "Mesh.h"
#include "config.h"

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

	void __debug__printbuffertoconsole();
private:
	Mesh chunkMesh;

	Block blockBuffer[config::chunkWidth * config::chunkHeight * config::chunkLayers];


    std::vector<Vertex> vertices = std::vector<Vertex>({
        Vertex(-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
        Vertex(0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
        Vertex(0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
        Vertex(-0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
        Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),

        Vertex(-0.5f, -0.5f,  0.5f, 0.0f, 0.6f, 0.3f),
        Vertex(0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
        Vertex(0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
        Vertex(0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f),
        Vertex(-0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f),

        Vertex(-0.5,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
        Vertex(-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
        Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
        Vertex(-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f),

        Vertex(0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
        Vertex(0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
        Vertex(0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
        Vertex(0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f),

        Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(0.5f, -0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
        Vertex(0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
        Vertex(0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
        Vertex(-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 0.6f, 0.3f),

        Vertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
        Vertex(0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
        Vertex(0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
        Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
        Vertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f)
     });

};