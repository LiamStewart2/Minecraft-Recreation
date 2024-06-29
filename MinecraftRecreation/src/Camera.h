#pragma once

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "config.h";

class Camera
{
public:
    Camera(glm::vec3 _up, glm::vec3 _front);

    glm::vec3 position; glm::vec3 front;    glm::vec3 up;
    glm::vec3 right;    glm::vec3 worldUp;

    float yaw; float pitch;
    float movementSpeed; float mouseSensitivity; float zoom;

    glm::mat4 getViewMatrix();

    // Input
    void processKeyboard(GLFWwindow* window);
    void processMouseMovement(float xOffset, float yOffset, GLboolean constraintPitch = true);
    void processMouseScroll(float yOffset);
private:
    void updateCameraVectors();
};