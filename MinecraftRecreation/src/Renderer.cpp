#include "Renderer.h"

#include <iostream>

/*
std::vector<Vertex> vertices = {
      Vertex( - 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
      Vertex( 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
      Vertex( 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f),
      Vertex( 0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(-0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
      Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
           
      Vertex(-0.5f, -0.5f,  0.5f, 0.0f, 0.6f, 0.3f),
      Vertex( 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
      Vertex( 0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
      Vertex( 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(-0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
              
      Vertex(-0.5,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
      Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
      Vertex(-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f),

      Vertex( 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex( 0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex( 0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
      Vertex( 0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
      Vertex( 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex( 0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f),

      Vertex(-0.5f, -0.5f, -0.5f, 0.)0f, 0.0f, 1.0f),
      Vertex( 0.5f, -0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex( 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
      Vertex( 0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
      Vertex(-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 0.6f, 0.3f),

      Vertex(-0.5f,  0.5f, -0.5f, 0.)0f, 0.0f, 1.0f),
      Vertex( 0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex( 0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
      Vertex( 0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
      Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f)
};
*/

const unsigned int indices[] = {
    0, 1, 2,  // first Triangle
    3, 2, 1  // first Triangle
};

void Renderer::initialize()
{
    shader = Shader("res/shaders/default/shader.vs", "res/shaders/default/shader.fs");

    loadMesh();
    mesh.loadMeshData(&vertices);
}

//TODO: remove this
void Renderer::loadMesh()
{
    vertices = std::vector<Vertex>({
      Vertex(-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
      Vertex(0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
      Vertex(0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(-0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
      Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),

      Vertex(-0.5f, -0.5f,  0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
      Vertex(0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
      Vertex(0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(-0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f),

      Vertex(-0.5,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
      Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
      Vertex(-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f),

      Vertex(0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f),
      Vertex(0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f),
      Vertex(0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(0.5f,  0.5f,  0.5f, 0.0f, 0.6f, 0.3f),

      Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(0.5f, -0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
      Vertex(0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
      Vertex(-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f, -0.5f, -0.5f, 0.0f, 0.6f, 0.3f),

      Vertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f),
      Vertex(0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f),
      Vertex(0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f),
      Vertex(-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f),
      Vertex(-0.5f,  0.5f, -0.5f, 0.0f, 0.6f, 0.3f)
    });
}

void Renderer::render(Camera* camera)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader.useShader();
    mesh.BindMeshBuffer();

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
    mesh.clean();
    shader.deleteShader();
}