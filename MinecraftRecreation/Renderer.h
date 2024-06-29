#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Renderer
{
public:
	Renderer() {}
	~Renderer() {}

	void initialize();

	void render();
	void terminate();
private:
	unsigned int vertexShader = 0;
	unsigned int fragmentShader = 0; 
	unsigned int shaderProgram = 0;

	unsigned int VBO = 0; 
	unsigned int VAO = 0;
	unsigned int EBO = 0;
};