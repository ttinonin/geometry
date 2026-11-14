#pragma once

#include <managers/EntityManager.h>
#include <entities/Player.h>
#include <managers/SystemManager.h>

class Level {
public:
	void Init();
	void Update(float deltaTime);
	void Draw();
private:
	EntityManager m_EntityManager;
	SystemManager m_SystemManager;
};