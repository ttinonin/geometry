#include "EnemyManager.h"
#include <entities/Enemy.h>
#include <utils/FileManager.h>

#ifdef _DEBUG
#include <utils/DebugConfig.h>
#endif // _DEBUG

void EnemyManager::Init(EntityManager& entities) {
	m_Entites = &entities;
	auto config = FileManager::GetConfigData();
	m_SpawnTimer = Timer(config["Enemy"][11]);
}

void EnemyManager::Update(float deltaTime) {
#ifdef _DEBUG
	auto& debug = DebugConfig::GetInstance();

	if (debug.ManualSpawn) {
		Spawn();
		debug.ManualSpawn = false;
	}

	if (debug.ActiveSpawning) {
		if (m_SpawnTimer.GetDuration() != debug.SpawnInterval) {
			m_SpawnTimer.SetDuration(debug.SpawnInterval);
		}

		m_SpawnTimer.Update(deltaTime);

		if (m_SpawnTimer.IsFinished()) {
			Spawn();
			m_SpawnTimer.Reset();
		}
	}
#else
	m_SpawnTimer.Update(deltaTime);

	if (m_SpawnTimer.IsFinished()) {
		Spawn();
		m_SpawnTimer.Reset();
	}
#endif // _DEBUG

	
}

void EnemyManager::Spawn() {
	auto enemy = m_Entites->AddEntity<Enemy>();
	enemy->Init();
}