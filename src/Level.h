#pragma once

#include <managers/EntityManager.h>
#include <entities/Player.h>

class Level {
public:
	void Init();
	void Update(float deltaTime);
	void Draw();
private:
	EntityManager m_EntityManager;
};