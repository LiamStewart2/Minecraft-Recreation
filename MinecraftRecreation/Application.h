#include <iostream>

#include "GLFW/glfw3.h"

#include "config.h"

#pragma once
class Application
{
public:
	Application();
	~Application() {}
private:
	GLFWwindow* window;

	void init();

	void mainloop();

	void handleEvents();
	void update();
	void render();

	void terminate();
};

