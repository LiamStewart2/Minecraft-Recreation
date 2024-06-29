#include "Renderer.h"

#include <iostream>

void Renderer::initialize()
{
    shader = Shader("res/shaders/default/shader.vs", "res/shaders/default/shader.fs");
}

void Renderer::render(Camera* camera, Mesh* mesh)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.useShader();
    mesh->BindMeshBuffer();

    glm::mat4 projection = glm::perspective(glm::radians(camera->zoom), (float)config::resolutionX / (float)config::resolutionY, 0.1f, 100.0f);
    glm::mat4 view = camera->getViewMatrix();
    glm::mat4 model = glm::mat4(1.0f);

    shader.setMat4("model", model);
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);

    glDrawArrays(GL_TRIANGLES, 0, mesh->getNumberOfVertices());
}

void Renderer::terminate()
{
    shader.deleteShader();
}