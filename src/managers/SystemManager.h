#pragma once

#include <systems/SMovement.h>
#include <systems/SInput.h>
#include <systems/SLifeSpan.h>
#include <systems/SCollision.h>
#include "EntityManager.h"

class SystemManager {
public:
	void Init(EntityManager& entities);
	void Update(float deltaTime);
private:
	EntityManager* m_Entities = nullptr;
	SMovement m_Movement;
	SLifeSpan m_LifeSpan;
	SInput m_Input;
	SCollision m_Collision;
};