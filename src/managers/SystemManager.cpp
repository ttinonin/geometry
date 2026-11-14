#include "SystemManager.h"

void SystemManager::Init(EntityManager& entities) {
	m_Entities = &entities;
}

void SystemManager::Update(float deltaTime) {
	m_Movement.Update(*m_Entities, deltaTime);
}