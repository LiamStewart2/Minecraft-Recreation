#pragma once

#include "glm.hpp"

struct config {
	// Window Settings
	const static int resolutionX = 1920;
	const static int resolutionY = 1080;

	// Camera Settings
	constexpr static glm::vec3 cameraStartPosition = glm::vec3(0.0f, 22.0f, 0.0f);
	constexpr static float cameraSensitivity = 0.1f;
	constexpr static float cameraSpeed = 0.5f;
	const static int zoom = 85;
	const static int yaw = -90;
	const static int pitch = 0;

	// World Settings
	const static unsigned int chunkWidth = 64;
	const static unsigned int chunkHeight = 64;
	const static unsigned int chunkLayers = 64;

	const static int renderDistance = 32;
};