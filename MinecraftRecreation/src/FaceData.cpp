#include "FaceData.h"

std::vector<Vertex> FaceData::TOP = std::vector<Vertex>{
	Vertex(-0.5f,  0.5f, -0.5f, 0, 1, 0),
	Vertex( 0.5f,  0.5f, -0.5f, 0, 1, 0),
	Vertex(-0.5f,  0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f,  0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f,  0.5f, -0.5f, 0, 1, 0),
	Vertex(-0.5f,  0.5f,  0.5f, 0, 1, 0),
};

std::vector<Vertex> FaceData::BOTTOM = std::vector<Vertex>{
	Vertex(-0.5f, -0.5f, -0.5f, 0, 1, 0),
	Vertex( 0.5f, -0.5f, -0.5f, 0, 1, 0),
	Vertex(-0.5f, -0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f, -0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f, -0.5f, -0.5f, 0, 1, 0),
	Vertex(-0.5f, -0.5f,  0.5f, 0, 1, 0),
};

std::vector<Vertex> FaceData::FRONT = std::vector<Vertex>{
	Vertex(-0.5f,   0.5f, -0.5f, 0, 1, 0),
	Vertex( 0.5f,   0.5f, -0.5f, 0, 1, 0),
	Vertex(-0.5f,  -0.5f, -0.5f, 0, 1, 0),
	Vertex( 0.5f,   0.5f, -0.5f, 0, 1, 0),
	Vertex( 0.5f,  -0.5f, -0.5f, 0, 1, 0),
	Vertex(-0.5f,  -0.5f, -0.5f, 0, 1, 0)
};

std::vector<Vertex> FaceData::BACK = std::vector<Vertex>{
	Vertex(-0.5f,   0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f,   0.5f,  0.5f, 0, 1, 0),
	Vertex(-0.5f,  -0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f,   0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f,  -0.5f,  0.5f, 0, 1, 0),
	Vertex(-0.5f,  -0.5f,  0.5f, 0, 1, 0)
};

std::vector<Vertex> FaceData::LEFT = std::vector<Vertex>{
	Vertex(-0.5f,   0.5f, -0.5f, 0, 1, 0),
	Vertex(-0.5f,   0.5f,  0.5f, 0, 1, 0),
	Vertex(-0.5f,  -0.5f, -0.5f, 0, 1, 0),
	Vertex(-0.5f,   0.5f,  0.5f, 0, 1, 0),
	Vertex(-0.5f,  -0.5f,  0.5f, 0, 1, 0),
	Vertex(-0.5f,  -0.5f, -0.5f, 0, 1, 0)
};

std::vector<Vertex> FaceData::RIGHT = std::vector<Vertex>{
	Vertex( 0.5f,   0.5f, -0.5f, 0, 1, 0),
	Vertex( 0.5f,   0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f,  -0.5f, -0.5f, 0, 1, 0),
	Vertex( 0.5f,   0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f,  -0.5f,  0.5f, 0, 1, 0),
	Vertex( 0.5f,  -0.5f, -0.5f, 0, 1, 0)
};