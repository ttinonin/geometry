#include "Level.h"

void Level::Init() {
	auto player = m_EntityManager.AddEntity<Player>();
	player->Init();
}

void Level::Draw() {
	for (const auto& entity : m_EntityManager.GetEntities("player")) {
		entity->Draw();
	}
}

void Level::Update(float deltaTime) {
	m_EntityManager.Update();
}