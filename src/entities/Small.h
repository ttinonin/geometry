#pragma once

#include "Entity.h"

class Small : public Entity {
public:
	Small(size_t id) : Entity("small", id) {}

	void Init(int radius, int speed, Vector2 position, Vector2 velocity, Color fillColor, Color outlineColor, int pointCount, int thickness, int lifespan);
	void Draw() override;
	void Update(float deltaTime) override;
};