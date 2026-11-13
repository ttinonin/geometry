#include "Player.h"

void Player::Init() {
	Add<CShape>();
	Add<CTransform>(Vector2{ 30.0f, 30.0f }, Vector2{10.0f, 10.0f});
}

void Player::Draw() {
	auto& shape = Get<CShape>();
	auto& transform = Get<CTransform>();

	DrawPolyLinesEx(
		transform.Position, 
		shape.Circle.GetPointCount(), 
		shape.Circle.GetRadius(),
		shape.Circle.GetRotation(),
		shape.Circle.GetThickness(),
		shape.Circle.GetOutlineColor()
	);
}