#pragma once

#include <managers/EntityManager.h>
#include <entities/Player.h>
#include <managers/SystemManager.h>
#include <managers/EnemyManager.h>

class Level {
public:
	void Init();
	void Update(float deltaTime);
	void Draw();
private:
	EnemyManager m_EnemyManager;
	EntityManager m_EntityManager;
	SystemManager m_SystemManager;
};