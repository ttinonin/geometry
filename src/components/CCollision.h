#pragma once

#include "Component.h"

class CCollision : public Component {
public:
	CCollision() {}
	CCollision(float radius) : Radius(radius) {}
	float Radius = 0.0f;
};