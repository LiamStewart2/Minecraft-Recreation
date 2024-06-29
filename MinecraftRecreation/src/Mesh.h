#pragma once

#include <iostream>
#include <vector>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Vertex.h"

class Mesh
{
public:
	Mesh() {}
	~Mesh() {}

	void loadMeshData(std::vector<Vertex>* Vertices);
	void BindMeshBuffer();

	void clean();
private:
	std::vector<Vertex> vertices;

	unsigned int VAO = 0;
	unsigned int VBO = 0;
};