#pragma once

#include <managers/EntityManager.h>

class SMovement {
public:
	void Update(EntityManager& entityManager, float deltaTime);
private:
	void Rotate(EntityManager& entityManager, float deltaTime);
	void Move(EntityManager& entityManager, float deltaTime);
};