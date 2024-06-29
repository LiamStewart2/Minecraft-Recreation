#include "Renderer.h"

#include <iostream>

void Renderer::initialize()
{
    shader = Shader("res/shaders/default/shader.vs", "res/shaders/default/shader.fs");
}

void Renderer::clear()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(Camera* camera, Mesh* mesh)
{
    shader.useShader();
    mesh->BindMeshBuffer();

    glm::mat4 projection = glm::perspective(glm::radians(camera->zoom), (float)config::resolutionX / (float)config::resolutionY, 0.1f, 100.0f);

    shader.setMat4("model", mesh->getModel());
    shader.setMat4("view", camera->getViewMatrix());
    shader.setMat4("projection", projection);

    glDrawArrays(GL_TRIANGLES, 0, mesh->getNumberOfVertices());
}

void Renderer::terminate()
{
    shader.deleteShader();
}