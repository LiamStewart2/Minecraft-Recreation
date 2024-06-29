#include "Application.h"

Application::Application()
{
	init();
	mainloop();
    terminate();
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{ 
    glViewport(0, 0, width, height); 
}

void Application::init()
{
    if (!glfwInit())
        std::cerr << "[APPLICATION::INIT]" << "glfw init failed" << std::endl;
    else
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(config::resolutionX, config::resolutionY, "Minecraft Recreation", NULL, NULL);
        glfwMaximizeWindow(window);
        if (!window)
        {
            glfwTerminate();
            std::cerr << "[APPLICATION::INIT]" << "window creation failed" << std::endl;
        }
        else
        {
            glfwMakeContextCurrent(window);
            glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

            GLenum err = glewInit();
            if (err != GLEW_OK)
            {
                std::cerr << glewGetErrorString(err) << std::endl;
                terminate();
            }
            else
            {
                start();
            }
        }
    }
}

void Application::start()
{
    renderer.initialize();
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
    renderer.render();

    glfwSwapBuffers(window);
}

void Application::terminate()
{
    glfwTerminate();
    renderer.terminate();
}