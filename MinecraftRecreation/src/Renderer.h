#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Shader.h"

class Renderer
{
public:
	Renderer() {}
	~Renderer() {}

	void initialize();

	void render();
	void terminate();
private:
	Shader shader;

	unsigned int VBO = 0; 
	unsigned int VAO = 0;
	unsigned int EBO = 0;
};