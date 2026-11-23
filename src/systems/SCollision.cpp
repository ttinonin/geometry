#include "SCollision.h"
#include <entities/Small.h>
#include <utils/FileManager.h>

void SCollision::Update(EntityManager& entityManager, float deltaTime) {
	auto& entities = entityManager.GetEntities();
	auto config = FileManager::GetConfigData();
	auto& score = entityManager.GetEntities("player")[0]->Get<CScore>();

	for (size_t i = 0; i < entities.size(); i++) {
		auto& entityA = entities[i];

		if (!entityA->Has<CCollision>() || !entityA->Has<CTransform>() || !entityA->Has<CShape>()) continue;

		for (size_t j = i + 1; j < entities.size(); j++) {
			auto& entityB = entities[j];

			if (!entityB->Has<CCollision>() || !entityB->Has<CTransform>() || !entityB->Has<CShape>()) continue;

			if (CheckCollisionCircles(
				entityA->Get<CTransform>().Position,
				entityA->Get<CShape>().Circle.GetRadius(),
				entityB->Get<CTransform>().Position,
				entityB->Get<CShape>().Circle.GetRadius()
			)) {
				const std::string& tagA = entityA->GetTag();
				const std::string& tagB = entityB->GetTag();

				if (IsCollisionPair(tagA, tagB, "bullet", "enemy")) {
					auto enemy = GetEntityByTag(entityA, entityB, "enemy");
					auto bullet = GetEntityByTag(entityA, entityB, "bullet");

					bullet->Destroy();

					auto& enemyShape = enemy->Get<CShape>();
					auto& enemyTransform = enemy->Get<CTransform>();

					int vertices = enemyShape.Circle.GetPointCount();
					float angleStep = 360.0f / vertices;

					for (int i = 0; i < vertices; i++) {
						float angle = (i * angleStep) * DEG2RAD;

						Vector2 direction = {
							cosf(angle),
							sinf(angle)
						};

						auto& small = entityManager.AddEntity<Small>();
						small->Init(
							8,
							100,
							enemyTransform.Position,
							direction,
							enemyShape.Circle.GetFillColor(),
							enemyShape.Circle.GetOutlineColor(),
							vertices,
							enemyShape.Circle.GetThickness(),
							config["Enemy"][10]
						);
					}
					
					score.Increment(1);
					enemy->Destroy();
				}

				if (IsCollisionPair(tagA, tagB, "bullet", "small")) {
					entityA->Destroy();
					entityB->Destroy();
				}

				if (IsCollisionPair(tagA, tagB, "player", "small")) {
					auto player = GetEntityByTag(entityA, entityB, "player");
					auto small = GetEntityByTag(entityA, entityB, "small");

					score.Decrement(1);
					small->Destroy();
				}

				if (IsCollisionPair(tagA, tagB, "player", "enemy")) {
					score.Score = 0;
				}
			}
		}
	}
}