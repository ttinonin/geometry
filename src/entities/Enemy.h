#pragma once

#include "Entity.h"

class Enemy : public Entity {
public:
	Enemy(size_t id) : Entity("enemy", id) {}

	void Init();
	void Draw() override;
	void Update(float deltaTime) override;
};