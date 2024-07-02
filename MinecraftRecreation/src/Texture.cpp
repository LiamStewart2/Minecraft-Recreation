#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void Texture::loadTexture(const char* textureFilePath)
{
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(textureFilePath, &width, &height, &nrChannels, 0);

	if (data)
	{
		GLint channel = -1;
		if (nrChannels == 3)
		{
			std::cout << "yyup";
			channel = GL_RGB;
		}
		else
			channel = GL_RGBA;

		glTexImage2D(GL_TEXTURE_2D, 0, channel, width, height, 0, channel, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
		std::cout << "TEXTURE::LOAD FAILED" << std::endl;
	stbi_image_free(data);
}

void Texture::useTexture()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
}