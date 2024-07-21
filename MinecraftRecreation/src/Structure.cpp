#include "Structure.h"

Structure::Structure(const char* filepath)
{
	std::ifstream structureDataFile(filepath);
	nlohmann::json structureData;

	if (!structureDataFile.is_open())
	{
		std::cerr << "Unable to open the structure file: " << filepath << "\n";
		return;
	}

	structureDataFile >> structureData;
	structureDataFile.close();

	structureName = structureData["Name"];

	for (int i = 0; i < structureData["Blocks"].size(); i++)
	{
		instruction _instruction;
		_instruction.blockPosition = glm::vec3(structureData["Blocks"][i]["BlockPosition"][0], structureData["Blocks"][i]["BlockPosition"][1], structureData["Blocks"][i]["BlockPosition"][2]);
		_instruction.blockType = &BlockDatabase::OakLog;
		instructions.push_back(_instruction);
	}
}