#include "SInput.h"
#include <raylib.h>

void SInput::Update(EntityManager& entityManager, float deltaTime) {
	for (auto& entity : entityManager.GetEntities()) {
		if (!entity->Has<CInput>()) continue;

		auto& input = entity->Get<CInput>();

		input.Up = IsKeyDown(KEY_W);
		input.Down = IsKeyDown(KEY_S);
		input.Left = IsKeyDown(KEY_A);
		input.Right = IsKeyDown(KEY_D);
	}
}