#include "Mesh.h"

void Mesh::loadMeshData(std::vector<Vertex>* Vertices)
{
	for (Vertex v : *Vertices)
		vertices.push_back(v);
	generateMeshBuffers();
}
void Mesh::loadMeshData(std::vector<Vertex>* Vertices, glm::vec3 offset)
{
	for (Vertex v : *Vertices)
	{
		vertices.push_back(v);
		vertices.back().x += offset.x;
		vertices.back().y += offset.y;
		vertices.back().z += offset.z;
	}
	generateMeshBuffers();
}


void Mesh::generateMeshBuffers()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices.front(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

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