#pragma once

#include "entities/Entity.h"
#include <raylib.h>

class Bullet : public Entity {
public:
	Bullet(size_t id) : Entity("bullet", id) {}

	void Init(Vector2 postition, Vector2 velocity);
	void Draw() override;
	void Update(float deltaTime) override;
};