#include "SMovement.h"

#include <raymath.h>

#ifdef _DEBUG
#include <utils/DebugConfig.h>
#endif // _DEBUG


void SMovement::Update(EntityManager& entityManager, float deltaTime) {
	Rotate(entityManager, deltaTime);
#ifdef _DEBUG
	auto& debug = DebugConfig::GetInstance();
	if (debug.ActiveMovement) {
		Move(entityManager, deltaTime);
	}
#else 
	Move(entityManager, deltaTime);
#endif // _DEBUG

	
}

void SMovement::Rotate(EntityManager& entityManager, float deltaTime) {
	for (auto& entity : entityManager.GetEntities()) {
		if (!entity->Has<CShape>() || !entity->Has<CTransform>()) continue;

		auto& transform = entity->Get<CTransform>();
		auto& shape = entity->Get<CShape>();

		transform.angle += 3.0f;
		shape.Circle.SetRotation(transform.angle);
	}
}

void SMovement::Move(EntityManager& entityManager, float deltaTime) {
	for (auto& entity : entityManager.GetEntities()) {
		if (!entity->Has<CTransform>()) continue;

		auto& transform = entity->Get<CTransform>();

		transform.Position.x += transform.Velocity.x * deltaTime * transform.Scale.x;
		transform.Position.y += transform.Velocity.y * deltaTime * transform.Scale.y;

		if (!entity->Has<CInput>()) continue;

		auto& input = entity->Get<CInput>();
		Vector2 inputVector = {};

		if (input.Up) {
			inputVector.y -= 1.0f;
		}

		if (input.Down) {
			inputVector.y += 1.0f;
		}

		if (input.Left) {
			inputVector.x -= 1.0f;
		}

		if (input.Right) {
			inputVector.x += 1.0f;
		}

		if (Vector2Length(inputVector) != 0.0f) {
			inputVector = Vector2Normalize(inputVector);
		}

		transform.Velocity = inputVector;
	}
}