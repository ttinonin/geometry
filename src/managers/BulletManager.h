#pragma once

#include "EntityManager.h"

class BulletManager {
public:
	void Init(EntityManager& entities);
	void Update(float deltaTime);
	void Spawn(Vector2 mousePosition);
private:
	EntityManager* m_Entites = nullptr;
};