#pragma once

#include <managers/EntityManager.h>
#include <entities/Player.h>
#include <managers/SystemManager.h>
#include <managers/EnemyManager.h>
#include <managers/BulletManager.h>

class Level {
public:
	void Init();
	void Update(float deltaTime);
	void Draw();
private:
	EnemyManager m_EnemyManager;
	BulletManager m_BulletManager;
	EntityManager m_EntityManager;
	SystemManager m_SystemManager;
};