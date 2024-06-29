#pragma once

struct Vertex
{
public:
	Vertex(float X, float Y, float Z, float R, float G, float B) : x(X), y(Y), z(Z), r(R), g(G), b(B) {}
	~Vertex() {}

	float x = 0; float y = 0; float z = 0; // Position data
	float r = 0; float g = 0; float b = 0; // Colour data
	//float tx = 0; float ty = 0;			   // Texture coordinate data
};

