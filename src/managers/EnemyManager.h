#pragma once

#include "EntityManager.h"
#include <utils/Timer.h>

class EnemyManager {
public:
	void Init(EntityManager& entities);
	void Update(float deltaTime);
	void Spawn();
private:
	EntityManager* m_Entites = nullptr;
	Timer m_SpawnTimer{ 2.0f };
};