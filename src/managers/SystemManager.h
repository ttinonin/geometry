#pragma once

#include <systems/SMovement.h>
#include "EntityManager.h"

class SystemManager {
public:
	void Init(EntityManager& entities);
	void Update(float deltaTime);
private:
	EntityManager* m_Entities = nullptr;
	SMovement m_Movement;
};