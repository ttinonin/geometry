#pragma once

#include "Entity.h"
#include <raylib.h>

class Player : public Entity {
public:
	Player(size_t id) : Entity("player", id) {}

	void Init();
	void Draw() override;
	void Update(float deltaTime) override;
};