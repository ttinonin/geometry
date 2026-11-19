#include "SMovement.h"
#include <utils/FileManager.h>
#include <raymath.h>

#ifdef _DEBUG
#include <utils/DebugConfig.h>
#endif // _DEBUG


void SMovement::Update(EntityManager& entityManager, float deltaTime) {
	for (auto& entity : entityManager.GetEntities()) {
		Rotate(entity, deltaTime);
		PlayerScreenLimit(entity, deltaTime);
		EnemyScreenLimit(entity, deltaTime);
#ifdef _DEBUG
		auto& debug = DebugConfig::GetInstance();
		if (debug.ActiveMovement) {
			Move(entity, deltaTime);
		}
#else 
		Rotate(entity, deltaTime);
		PlayerScreenLimit(entity, deltaTime);
		EnemyScreenLimit(entity, deltaTime);
		Move(entity, deltaTime);
#endif // _DEBUG
	}
}

void SMovement::Rotate(const std::shared_ptr<Entity>& entity, float deltaTime) {
	if (!entity->Has<CShape>() || !entity->Has<CTransform>()) return;

	auto& transform = entity->Get<CTransform>();
	auto& shape = entity->Get<CShape>();

	transform.angle += 3.0f;
	shape.Circle.SetRotation(transform.angle);
}

void SMovement::EnemyScreenLimit(const std::shared_ptr<Entity>& entity, float deltaTime) {
	auto config = FileManager::GetConfigData();
	if (!entity->Has<CShape>() || !entity->Has<CTransform>() || entity->GetTag() != "enemy") return;

	auto& transform = entity->Get<CTransform>();
	auto& shape = entity->Get<CShape>();

	float windowWidth = (float)config["Window"][0];
	float windowHeight = (float)config["Window"][1];
	float radius = shape.Circle.GetRadius();

	if (transform.Position.x - radius <= 0.0f ||
		transform.Position.x + radius >= windowWidth) {
		transform.Velocity.x *= -1.0f;
	}

	if (transform.Position.y - radius <= 0.0f ||
		transform.Position.y + radius >= windowHeight) {
		transform.Velocity.y *= -1.0f;
	}
}

void SMovement::PlayerScreenLimit(const std::shared_ptr<Entity>& entity, float deltaTime) {
	auto config = FileManager::GetConfigData();
	if (!entity->Has<CShape>() || !entity->Has<CTransform>() || entity->GetTag() != "player") return;

	auto& transform = entity->Get<CTransform>();
	auto& shape = entity->Get<CShape>();

	float windowWidth = (float)config["Window"][0];
	float windowHeight = (float)config["Window"][1];
	float radius = shape.Circle.GetRadius();

	if (transform.Position.x - radius <= 0.0f) {
		transform.Position.x = radius;
	}

	if (transform.Position.x + radius >= windowWidth) {
		transform.Position.x = windowWidth - radius;
	}

	if (transform.Position.y - radius <= 0.0f) {
		transform.Position.y = radius;
	}

	if (transform.Position.y + radius >= windowHeight) {
		transform.Position.y = windowHeight - radius;
	}
}

void SMovement::Move(const std::shared_ptr<Entity>& entity, float deltaTime) {
	if (!entity->Has<CTransform>()) return;

	auto& transform = entity->Get<CTransform>();

	transform.Position.x += transform.Velocity.x * deltaTime * transform.Scale.x;
	transform.Position.y += transform.Velocity.y * deltaTime * transform.Scale.y;

	if (!entity->Has<CInput>()) return;

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