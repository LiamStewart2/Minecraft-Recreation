#pragma once

#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "config.h"
#include "Renderer.h"
#include "Camera.h"
#include "Mesh.h"
#include "Chunk.h"

class Application
{
public:
	Application();
	~Application() {}

	void onMouseMove(double mouseX, double mouseY);
	void onMouseScroll(double xOffset, double yOffset);
private:
	GLFWwindow* window;
	Renderer renderer;
	Camera camera = Camera(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));

	Mesh testMesh;
	std::vector<Vertex> testVertices;

	std::vector<Mesh> meshes;
	std::vector<Vertex> vertices;
	void loadMesh();

	Chunk chunk;

	float mouseXPos = -1; float mouseYPos = -1;

	void init();

	void start();
	void mainloop();

	void handleEvents();
	void update();
	void render();

	void terminate();
};

