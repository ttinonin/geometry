#include "SCollision.h"
#include <iostream>

void SCollision::Update(EntityManager& entityManager, float deltaTime) {
	auto& entities = entityManager.GetEntities();

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
					std::cout << "Bullet hits enemy\n";
				}

				if (IsCollisionPair(tagA, tagB, "bullet", "small")) {
					std::cout << "Bullet hits small\n";
				}

				if (IsCollisionPair(tagA, tagB, "player", "small")) {
					std::cout << "Player hits small\n";
				}

				if (IsCollisionPair(tagA, tagB, "player", "enemy")) {
					std::cout << "Player hits enemy\n";
				}
			}
		}
	}
}