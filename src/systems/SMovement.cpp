#include "SMovement.h"

void SMovement::Update(EntityManager& entityManager, float deltaTime) {
	for (auto& entity : entityManager.GetEntities()) {
		if (!entity->Has<CShape>() || !entity->Has<CTransform>()) continue;

		auto& transform = entity->Get<CTransform>();
		auto& shape = entity->Get<CShape>();

		transform.angle += 1.0f;
		shape.Circle.SetRotation(transform.angle);
	}
}