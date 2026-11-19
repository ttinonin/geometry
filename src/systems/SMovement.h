#pragma once

#include <managers/EntityManager.h>

class SMovement {
public:
	void Update(EntityManager& entityManager, float deltaTime);
private:
	void PlayerScreenLimit(const std::shared_ptr<Entity>& entity, float deltaTime);
	void EnemyScreenLimit(const std::shared_ptr<Entity>& entity, float deltaTime);
	void Rotate(const std::shared_ptr<Entity>& entity, float deltaTime);
	void Move(const std::shared_ptr<Entity>& entity, float deltaTime);
};