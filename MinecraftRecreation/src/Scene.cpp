#include "Scene.h"

void Scene::initChunkMap(TextureAtlas* textureAtlas)
{
	chunkMap.clear();
    texture = textureAtlas;

	for (int i = config::renderDistance * -1; i <= config::renderDistance; i++)
	{
		for (int j = config::renderDistance * -1; j <= config::renderDistance; j++)
		{
            Chunk* newChunk = new Chunk(glm::vec2(i, j));

            newChunk->generateTerrain();
            newChunk->generateChunkMesh(texture);

            chunkMap.push_back(newChunk);
		}
	}
    updateAllChunkEdges();
}

void Scene::chunkGenerationQueueManager()
{
    double startTime = glfwGetTime();
    while (chunkGenerationQueue.size() > 0 && glfwGetTime() < startTime + chunkGenerationAllowance)
    {
        glm::vec2 chunkPosition = chunkGenerationQueue.front();
        chunkGenerationQueue.pop_front();

        Chunk* newChunk = new Chunk(chunkPosition);

        newChunk->generateTerrain();
        newChunk->generateChunkMesh(texture);

        chunkMap.push_back(newChunk);

        updateChunkEdges(newChunk);
        std::vector<glm::vec2> directions = { glm::vec2(1, 0), glm::vec2(0, 1), glm::vec2(-1, 0), glm::vec2(0, -1) };
        for (glm::vec2 dir : directions)
        {
            Chunk* neighbourChunk = getChunk(newChunk->getWorldPosition() + dir);
            if (neighbourChunk != nullptr)
                updateChunkEdges(neighbourChunk);
        }
    }
}

void Scene::updateAllChunkEdges()
{
    for (Chunk* chunk : chunkMap)
    {
        updateChunkEdges(chunk);
    }
}

void Scene::updateChunkEdges(Chunk* chunk)
{
    // Check y- axis -- north
    Chunk* northernChunk = getChunk(chunk->getWorldPosition() + glm::vec2(0, -1));
    if (northernChunk != nullptr)
    {
        for (int x = 0; x < config::chunkWidth; x++)
        {
            for (int y = 0; y < config::chunkLayers; y++)
            {
                BlockType* currentBlock = chunk->getBlockAtPosition(x, y, 0);
                BlockType* northernBlock = northernChunk->getBlockAtPosition(x, y, config::chunkHeight - 1);

                if (currentBlock->air == false && northernBlock->air == true)
                {
                    chunk->chunkMesh.loadMeshData(&FaceData::FRONT, glm::vec3(x, y, 0), texture->getTextureCoordinateOffset(currentBlock->sideTexture));
                }
            }
        }
    }

    // Check y+ axis -- south
    Chunk* southernChunk = getChunk(chunk->getWorldPosition() + glm::vec2(0, 1));
    if (southernChunk != nullptr)
    {
        for (int x = 0; x < config::chunkWidth; x++)
        {
            for (int y = 0; y < config::chunkLayers; y++)
            {
                BlockType* currentBlock = chunk->getBlockAtPosition(x, y, config::chunkHeight - 1);
                BlockType* southernBlock = southernChunk->getBlockAtPosition(x, y, 0);

                if (currentBlock->air == false && southernBlock->air == true)
                {
                    chunk->chunkMesh.loadMeshData(&FaceData::BACK, glm::vec3(x, y, config::chunkHeight - 1), texture->getTextureCoordinateOffset(currentBlock->sideTexture));
                }
            }
        }
    }

    // Check x- axis -- west
    Chunk* westernChunk = getChunk(chunk->getWorldPosition() + glm::vec2(-1, 0));
    if (westernChunk != nullptr)
    {
        for (int z = 0; z < config::chunkHeight; z++)
        {
            for (int y = 0; y < config::chunkLayers; y++)
            {
                BlockType* currentBlock = chunk->getBlockAtPosition(0, y, z);
                BlockType* westernBlock = westernChunk->getBlockAtPosition(config::chunkWidth - 1, y, z);

                if (currentBlock->air == false && westernBlock->air == true)
                {
                    chunk->chunkMesh.loadMeshData(&FaceData::LEFT, glm::vec3(0, y, z), texture->getTextureCoordinateOffset(currentBlock->sideTexture));
                }
            }
        }
    }

    // Check x+ axis -- east
    Chunk* easternChunk = getChunk(chunk->getWorldPosition() + glm::vec2(1, 0));
    if (easternChunk != nullptr)
    {
        for (int z = 0; z < config::chunkHeight; z++)
        {
            for (int y = 0; y < config::chunkLayers; y++)
            {
                BlockType* currentBlock = chunk->getBlockAtPosition(config::chunkWidth - 1, y, z);
                BlockType* easternBlock = easternChunk->getBlockAtPosition(0, y, z);

                if (currentBlock->air == false && easternBlock->air == true)
                {
                    chunk->chunkMesh.loadMeshData(&FaceData::RIGHT, glm::vec3(config::chunkWidth - 1, y, z), texture->getTextureCoordinateOffset(currentBlock->sideTexture));
                }
            }
        }
    }

    chunk->updateChunkMeshBuffers();
}

void Scene::update(Camera* camera)
{
    dynamicChunkLoading(camera);
    chunkGenerationQueueManager();
}

void Scene::dynamicChunkLoading(Camera* camera)
{
    glm::vec2 currentCameraChunkPos = glm::vec2(
        floor(camera->position.x / config::chunkWidth),
        floor(camera->position.z / config::chunkHeight));

    if (currentCameraChunkPos == lastCameraChunkPos)
        return;

    //Load new chunks
    if (lastCameraChunkPos.x < currentCameraChunkPos.x)
    {
        std::cout << "+X\n"; 
        //moved increase x
        for (int i = config::renderDistance * -1; i <= config::renderDistance; i++)
        {
            glm::vec2 newChunkPosition = glm::vec2(currentCameraChunkPos.x + config::renderDistance, currentCameraChunkPos.y + i);
            if(getChunk(newChunkPosition) == nullptr && isPositionInChunkGenerationQueue(newChunkPosition) == false)
                addChunkToGenerationQueue(newChunkPosition);

            // delete old chunk

            glm::vec2 oldChunkPosition = glm::vec2(currentCameraChunkPos.x - config::renderDistance - 1, currentCameraChunkPos.y + i);

            if (isPositionInChunkGenerationQueue(oldChunkPosition))
                removeChunkFromGenerationQueue(oldChunkPosition);

            Chunk* oldChunk = getChunk(oldChunkPosition);
            while (oldChunk != nullptr)
            {
                chunkMap.erase(std::remove(chunkMap.begin(), chunkMap.end(), oldChunk));

                delete oldChunk;

                oldChunk = getChunk(oldChunkPosition);
            }
        }
    }
    if (lastCameraChunkPos.x > currentCameraChunkPos.x)
    {
        std::cout << "-X\n";
        //moved decrease x
        for (int i = config::renderDistance * -1; i <= config::renderDistance; i++)
        {
            // load new chunk
            glm::vec2 newChunkPosition = glm::vec2(currentCameraChunkPos.x - config::renderDistance, currentCameraChunkPos.y + i);
            if (getChunk(newChunkPosition) == nullptr && isPositionInChunkGenerationQueue(newChunkPosition) == false)
                addChunkToGenerationQueue(newChunkPosition);

            // delete old chunk

            glm::vec2 oldChunkPosition = glm::vec2(currentCameraChunkPos.x + config::renderDistance + 1, currentCameraChunkPos.y + i);

                if (isPositionInChunkGenerationQueue(oldChunkPosition))
                    removeChunkFromGenerationQueue(oldChunkPosition);

                Chunk* oldChunk = getChunk(oldChunkPosition);
            while (oldChunk != nullptr)
                {
                    chunkMap.erase(std::remove(chunkMap.begin(), chunkMap.end(), oldChunk));

                    delete oldChunk;

                oldChunk = getChunk(oldChunkPosition);
            }
        }
    }

    if (lastCameraChunkPos.y < currentCameraChunkPos.y)
    {
        std::cout << "+Y\n";
        //move increased y
        for (int i = config::renderDistance * -1; i <= config::renderDistance; i++)
        {
            glm::vec2 newChunkPosition = glm::vec2(currentCameraChunkPos.x + i, currentCameraChunkPos.y + config::renderDistance);
            if (getChunk(newChunkPosition) == nullptr && isPositionInChunkGenerationQueue(newChunkPosition) == false)
                addChunkToGenerationQueue(newChunkPosition);

            // delete old chunk

            glm::vec2 oldChunkPosition = glm::vec2(currentCameraChunkPos.x + i, currentCameraChunkPos.y - config::renderDistance - 1);

            if (isPositionInChunkGenerationQueue(oldChunkPosition))
                removeChunkFromGenerationQueue(oldChunkPosition);

            Chunk* oldChunk = getChunk(oldChunkPosition);
            while (oldChunk != nullptr)
            {
                chunkMap.erase(std::remove(chunkMap.begin(), chunkMap.end(), oldChunk));

                delete oldChunk;

                oldChunk = getChunk(oldChunkPosition);
            }
        }
    }
    if (lastCameraChunkPos.y > currentCameraChunkPos.y)
    {

        //moved decreased y
        std::cout << "-Y\n";
        for (int i = config::renderDistance * -1; i <= config::renderDistance; i++)
        {
            glm::vec2 newChunkPosition = glm::vec2(currentCameraChunkPos.x + i, currentCameraChunkPos.y - config::renderDistance);
            if (getChunk(newChunkPosition) == nullptr && isPositionInChunkGenerationQueue(newChunkPosition) == false)
                addChunkToGenerationQueue(newChunkPosition);
            // delete old chunk
            
            glm::vec2 oldChunkPosition = glm::vec2(currentCameraChunkPos.x + i, currentCameraChunkPos.y + config::renderDistance + 1);

            if(isPositionInChunkGenerationQueue(oldChunkPosition))
                removeChunkFromGenerationQueue(oldChunkPosition);

            Chunk* oldChunk = getChunk(oldChunkPosition);
            while (oldChunk != nullptr)
            {
                chunkMap.erase(std::remove(chunkMap.begin(), chunkMap.end(), oldChunk));

                delete oldChunk;

                oldChunk = getChunk(oldChunkPosition);
            }
        }
    }
    lastCameraChunkPos = currentCameraChunkPos;
}

void Scene::renderScene(Renderer* renderer, Camera* camera)
{
	for(Chunk* chunk : chunkMap)
		renderer->render(camera, chunk->getChunkMesh());
}

// Will return null position is invalid or isnt loaded
Chunk* Scene::getChunk(glm::vec2 chunkPosition)
{
	for (Chunk* chunk : chunkMap)
	{
		if(chunk->getWorldPosition() == chunkPosition)
			return chunk;
	}
	return nullptr;
}

void Scene::addChunkToGenerationQueue(glm::vec2 chunkPosition)
{
    chunkGenerationQueue.push_back(chunkPosition);
}

void Scene::removeChunkFromGenerationQueue(glm::vec2 chunkPosition)
{
    auto it = std::find(chunkGenerationQueue.begin(), chunkGenerationQueue.end(), chunkPosition);
    if (it != chunkGenerationQueue.end()) {
        chunkGenerationQueue.erase(it);
    }
}

bool Scene::isPositionInChunkGenerationQueue(glm::vec2 chunkPosition)
{
    for (int i = 0; i < chunkGenerationQueue.size(); i++)
    {
        if(chunkGenerationQueue[i] == chunkPosition)
            return true;
    }
    return false;
}

void Scene::deleteAllChunks()
{
    for (Chunk* chunk : chunkMap)
    {
        delete chunk;
    }

    chunkMap.clear();
}