#pragma once

#include "Component.h"
#include <raylib.h>

class CTransform : public Component {
public:
	CTransform() {};
	CTransform(Vector2 position, Vector2 velocity) : Position(position), Velocity(velocity) {}

	Vector2 Position = {};
	Vector2 Velocity = {};
	Vector2 Scale = {};
	float angle = 0.0f;
};