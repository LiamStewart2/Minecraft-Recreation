#pragma once

#include <iostream>
#include <vector>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "Vertex.h"

class Mesh
{
public:
	Mesh() { model = glm::mat4(1.0f); }
	~Mesh() {}

	void setPosition(float x, float y, float z);

	void loadMeshData(std::vector<Vertex>* Vertices);
	void loadMeshData(std::vector<Vertex>* Vertices, glm::vec3 offset);

	void BindMeshBuffer();

	unsigned int getNumberOfVertices() { return vertices.size(); }
	glm::mat4 getModel() { return model; }

	void clean();
private:
	std::vector<Vertex> vertices;
	glm::mat4 model;

	void generateMeshBuffers();

	unsigned int VAO = 0;
	unsigned int VBO = 0;
};