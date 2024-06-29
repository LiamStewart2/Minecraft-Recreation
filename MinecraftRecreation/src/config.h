#pragma once

struct config {
	// Window Settings
	const static int resolutionX = 1920;
	const static int resolutionY = 1080;

	// Camera Settings
	constexpr static float sensitivity = 0.1f;
	constexpr static float speed = 2.5f;
	const static int zoom = 45;
	const static int yaw = -90;
	const static int pitch = 0;
};