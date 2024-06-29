#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Shader.h"
#include "Camera.h"
#include "Mesh.h"
#include "Vertex.h"

class Renderer
{
public:
	Renderer() {}
	~Renderer() {}

	void initialize();
	void loadMesh();

	void render(Camera* camera);
	void terminate();
private:
	Shader shader;
	Mesh mesh;
	std::vector<Vertex> vertices;
};