#include "Mesh.h"

#include <cstddef>
#include <iostream>

void Mesh::loadMeshData(std::vector<Vertex>* Vertices)
{
	for (Vertex v : *Vertices)
		vertices.push_back(v);
}
void Mesh::loadMeshData(std::vector<Vertex>* Vertices, glm::vec3 positionOffset)
{
	for (Vertex v : *Vertices)
	{
		vertices.push_back(v);
		vertices.back().position += positionOffset;
	}
}
void Mesh::loadMeshData(std::vector<Vertex>* Vertices, glm::vec3 positionOffset, glm::vec2 textureOffset)
{
	for (Vertex v : *Vertices)
	{
		vertices.push_back(v);
		vertices.back().position += positionOffset;
		vertices.back().textureCoordinate += textureOffset;
	}
}


void Mesh::generateMeshBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices.front(), GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, colour));
	glEnableVertexAttribArray(1);
	// Texture Coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, textureCoordinate));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::setPosition(float x, float y, float z)
{
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(x, y, z));
}

void Mesh::BindMeshBuffer() 
{
	glBindVertexArray(VAO);
}

void Mesh::clean()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}