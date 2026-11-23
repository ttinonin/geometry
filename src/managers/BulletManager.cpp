#include "BulletManager.h"
#include <raymath.h>
#include <entities/Bullet.h>

void BulletManager::Init(EntityManager& entities) {
	m_Entites = &entities;
}

void BulletManager::Update(float deltaTime) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Spawn(GetMousePosition());
	}

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        SpawnSpecial();
    }
}

void BulletManager::SpawnSpecial() {
    auto& players = m_Entites->GetEntities("player");

    if (players.empty()) return;

    auto& player = players[0];

    Vector2 position = player->Get<CTransform>().Position;

    int vertices = player->Get<CShape>().Circle.GetPointCount();
    float angleStep = 360.0f / vertices;

    for (int i = 0; i < vertices; i++) {
        float angle = (i * angleStep) * DEG2RAD;

        Vector2 direction = {
            cosf(angle),
            sinf(angle)
        };

        auto bullet = m_Entites->AddEntity<Bullet>();

        bullet->Init(position, direction);
        bullet->Get<CShape>().Circle.SetFillColor(RED);
        bullet->Get<CShape>().Circle.SetOutlineColor(BLACK);
        bullet->Get<CLifeSpan>().mTimer.SetDuration(0.40f);
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