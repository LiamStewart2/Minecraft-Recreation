#pragma once

#include "glm.hpp"

struct Vertex
{
public:
	Vertex(float X, float Y, float Z, float R, float G, float B, float tx, float ty) 
	{
		position = glm::vec3(X, Y, Z);
		colour = glm::vec3(R, G, B);
		textureCoordinate = glm::vec2(tx, ty);
	}
	Vertex(glm::vec3 VertexPosition, glm::vec3 VertexColour, glm::vec2 VertexTextureCoordinate) : position(VertexPosition), colour(VertexColour), textureCoordinate(VertexTextureCoordinate) {	}
	Vertex(glm::vec3 VertexPosition, glm::vec2 VertexTextureCoordinate) : position(VertexPosition), colour(glm::vec3(1)), textureCoordinate(VertexTextureCoordinate) {	}
	~Vertex() {}

	glm::vec3 position = glm::vec3(0);
	glm::vec3 colour = glm::vec3(0);
	glm::vec2 textureCoordinate = glm::vec2(0);
};

