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
void mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
    Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
    app->onMouseMove(xPos, yPos);
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
    app->onMouseScroll(xoffset, yoffset);
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

            glfwSetWindowUserPointer(window, this);

            glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
            glfwSetCursorPosCallback(window, mouse_callback);
            glfwSetScrollCallback(window, scroll_callback);

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
    camera.processKeyboard(window);
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

void Application::onMouseMove(double mouseX, double mouseY)
{
    if (mouseXPos == -1 || mouseYPos == -1)
        mouseXPos = mouseX; mouseYPos = mouseY;

    float mouseXOffset = mouseX - mouseXPos;
    float mouseYOffset = mouseY - mouseYPos;

    mouseXPos = mouseX;
    mouseYPos = mouseY;

    camera.processMouseMovement(mouseXOffset, mouseYOffset);
}
void Application::onMouseScroll(double xOffset, double yOffset)
{
    camera.processMouseScroll(yOffset);
}