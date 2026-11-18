#include "Small.h"

void Small::Init(int radius, int speed, Vector2 position, Vector2 velocity, Color fillColor, Color outlineColor, int pointCount, int thickness, int lifespan) {
	Add<CTransform>(position, velocity);
	Get<CTransform>().Scale.x = speed;
	Get<CTransform>().Scale.y = speed;

	Add<CCollision>(radius);

	Add<CShape>(
		radius,
		pointCount,
		thickness,
		fillColor,
		outlineColor
	);

	Add<CLifeSpan>(lifespan);
}

void Small::Draw() {
	auto& shape = Get<CShape>();
	auto& transform = Get<CTransform>();

	DrawPoly(
		transform.Position,
		shape.Circle.GetPointCount(),
		shape.Circle.GetRadius(),
		shape.Circle.GetRotation(),
		shape.Circle.GetFillColor()
	);

	DrawPolyLinesEx(
		transform.Position,
		shape.Circle.GetPointCount(),
		shape.Circle.GetRadius(),
		shape.Circle.GetRotation(),
		shape.Circle.GetThickness(),
		shape.Circle.GetOutlineColor()
	);
}

void Small::Update(float deltaTime) {

}