#pragma once

#include "EngineComponent.h"
#include "InputManager.h"

class CameraControllerComponent : public EngineComponent
{
public:
	CameraControllerComponent(std::shared_ptr<Entity>e, std::shared_ptr<InputManager> _input);
	~CameraControllerComponent() override {};

	void earlyUpdate(float deltaTime) override;

	// can be turned in to references
	std::shared_ptr<InputManager> input;
	SDL_Window* window;

	float mouseSensitivity;
	float movementSpeed;

	bool useContoller;

private:
	float lastX, lastY, initMoveSpeed;
};
