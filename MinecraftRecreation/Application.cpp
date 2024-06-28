#include "Application.h"

Application::Application()
{
	init();
	mainloop();
    terminate();
}

void Application::init()
{
    if (!glfwInit())
        std::cerr << "[APPLICATION::INIT]" << "glfw init failed" << std::endl;
    else
    {
        window = glfwCreateWindow(config::resolutionX, config::resolutionY, "Minecraft Recreation", NULL, NULL);
        glfwMaximizeWindow(window);
        if (!window)
        {
            glfwTerminate();
            std::cerr << "[APPLICATION::INIT]" << "window creation failed" << std::endl;
        }
        else
            glfwMakeContextCurrent(window);
    }

}

void Application::mainloop()
{
    while (!glfwWindowShouldClose(window))
    {
        update();
        render();

        handleEvents();
    }
}

void Application::update()
{

}

void Application::handleEvents()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwDestroyWindow(window);

    glfwPollEvents();
}

void Application::render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //render here

    glfwSwapBuffers(window);
}

void Application::terminate()
{
    glfwTerminate();
}