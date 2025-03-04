# Minecraft-Recreation
### My second Minecraft-like voxel project

A few months before starting this project, i had finished working on my first minecraft clone.

*YouTube video showing off the project in its final state:* https://youtu.be/FT8pOJsxidc

This project however had many issues, the main ones being:
- optimization - essentially, every frame the chunk mesh was being recreated. the only optimization in place was the use of face culling, where faces that where hidden by other blocks wouldnt be rendererd
- architecture - it was my first OpenGL project everytime i added a feature i was learning a new feature and just chucking it in. the application class had most of the logic, leaving the project a mess
- structure handling - the method used to implement trees was very unexpandable and rushed. trees couldnt be placed on chunk boundaries and would often overlap. also, new tree types would be increasingly difficult to implement

### The Solution

In this new project, i have implemented numerous technologies and completely reworked the engine to support more expansion.

One of the many massive improvements, its the implementation of a chunk mesh. the chunk mesh is created as the chunk is generated. the chunk mesh stores all the vertex data of the chunk. the mesh is also responsible for managing the OpenGL buffers for that object. meshes are then sent to the renderer.

# Project Setup
the project currently has no build system, and relies on visual studio 2022. in the future a build system may be implemented.
there is an issue with the libraries not being pushed to the branch
