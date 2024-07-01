#pragma once

#include <vector>

#include "Vertex.h"

struct FaceData {
	static std::vector<Vertex> TOP;
	static std::vector<Vertex> BOTTOM;
	static std::vector<Vertex> FRONT;
	static std::vector<Vertex> BACK;
	static std::vector<Vertex> LEFT;
	static std::vector<Vertex> RIGHT;
};