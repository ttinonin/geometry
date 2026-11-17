#include "BulletManager.h"
#include <raymath.h>
#include <entities/Bullet.h>

void BulletManager::Init(EntityManager& entities) {
	m_Entites = &entities;
}

void BulletManager::Update(float deltaTime) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
		Spawn(GetMousePosition());
	}
}

void BulletManager::Spawn(Vector2 mousePosition) {
    auto& players = m_Entites->GetEntities("player");

    if (players.empty()) return;

    auto& player = players[0];

    Vector2 position = player->Get<CTransform>().Position;

    Vector2 direction = Vector2Subtract(mousePosition, position);

    if (Vector2Length(direction) != 0.0f) {
        direction = Vector2Normalize(direction);
    }

    auto bullet = m_Entites->AddEntity<Bullet>();

    bullet->Init(position, direction);
}