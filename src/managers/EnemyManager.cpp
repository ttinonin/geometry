#include "EnemyManager.h"
#include <entities/Enemy.h>

void EnemyManager::Init(EntityManager& entities) {
	m_Entites = &entities;
}

void EnemyManager::Update() {

}

void EnemyManager::Spawn() {
	auto enemy = m_Entites->AddEntity<Enemy>();
	enemy->Init();
}