#include "Renderer.h"

#include <iostream>

const float vertices[] = {
     - 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
       0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
       0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f,
      -0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
      -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
                        
      -0.5f, -0.5f,  0.5f, 0.0f, 0.6f, 0.3f,
       0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,
       0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
       0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
      -0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f,
      -0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,
                         
      -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
      -0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f,
      -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
      -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
      -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
      -0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f,

       0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
       0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f,
       0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
       0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
       0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
       0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f,

      -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
       0.5f, -0.5f, -0.5f, 0.0f, 0.6f, 0.3f,
       0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f,
       0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
      -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
      -0.5f, -0.5f, -0.5f, 0.0f, 0.6f, 0.3f,

      -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
       0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f,
       0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,
       0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
      -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,
      -0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f,
};
const unsigned int indices[] = {
    0, 1, 2,  // first Triangle
    3, 2, 1  // first Triangle
};

void Renderer::initialize()
{
    // Initialize Shaders
    shader = Shader("res/shaders/default/shader.vs", "res/shaders/default/shader.fs");

    // Initialize buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderer::render(Camera* camera)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.useShader();
    glBindVertexArray(VAO);

    glm::mat4 projection = glm::perspective(glm::radians(camera->zoom), (float)config::resolutionX / (float)config::resolutionY, 0.1f, 100.0f);
    glm::mat4 view = camera->getViewMatrix();
    glm::mat4 model = glm::mat4(1.0f);

    shader.setMat4("model", model);
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Renderer::terminate()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    shader.deleteShader();
}