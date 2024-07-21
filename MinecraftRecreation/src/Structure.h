#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "glm.hpp"
#include "json.hpp"

#include "BlockDatabase.h"

struct instruction
{
	glm::vec3 blockPosition;
	BlockType* blockType;
};

class Structure
{
public:
	Structure() {}
	Structure(const char* filepath);
	~Structure() {}

	std::string structureName = "";
	std::vector<instruction> instructions;
};