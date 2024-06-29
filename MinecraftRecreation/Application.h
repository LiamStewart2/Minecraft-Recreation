#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "config.h"
#include "Renderer.h"

#pragma once
class Application
{
public:
	Application();
	~Application() {}
private:
	GLFWwindow* window;
	Renderer renderer;

	void init();

	void start();
	void mainloop();

	void handleEvents();
	void update();
	void render();

	void terminate();
};

