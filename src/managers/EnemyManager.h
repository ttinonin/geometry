#pragma once

#include "EntityManager.h"

class EnemyManager {
public:
	void Init(EntityManager& entities);
	void Update();
	void Spawn();
private:
	EntityManager* m_Entites = nullptr;
};