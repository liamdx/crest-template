#pragma once
#include "Common.h"

class PhysicsManager
{
public:
	PhysicsManager();
	~PhysicsManager() {};
	static constexpr float fixedTimeStep = 1.0f / 60.0f;
	rp3d::Vector3 gravity;

	void setGravity(glm::vec3 _gravity);
	void update(float deltaTime);

	//add shape functionality

	rp3d::RigidBody* addRigidbody();

	inline float getFactor() { return factor; }
	float accumulator, deltaTime, lastFrame, factor;
	rp3d::DynamicsWorld world;
};