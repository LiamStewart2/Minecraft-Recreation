#pragma once

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Texture 
{
public:
	void loadTexture(const char* textureFilePath);
	void useTexture();
	unsigned int textureID = 0;
	int width = 0; int height = 0; int nrChannels = 0;
};