#include "SystemManager.h"

void SystemManager::Init(EntityManager& entities) {
	m_Entities = &entities;
}

void SystemManager::Update(float deltaTime) {
	m_Movement.Update(*m_Entities, deltaTime);
	m_Input.Update(*m_Entities, deltaTime);
	m_LifeSpan.Update(*m_Entities, deltaTime);
	m_Collision.Update(*m_Entities, deltaTime);
}