#include "BlockDatabase.h"

BlockType BlockDatabase::Air = BlockType("Air", true);
BlockType BlockDatabase::Grass = BlockType("Grass", glm::vec2(1, 0), glm::vec2(2, 0), glm::vec2(0, 0));
BlockType BlockDatabase::Dirt = BlockType("Dirt", glm::vec2(2, 0));
BlockType BlockDatabase::Stone = BlockType("Stone", glm::vec2(3, 0));