#include "Bullet.h"
#include <utils/FileManager.h>

void Bullet::Init(Vector2 postition, Vector2 velocity) {
	ConfigMap config = FileManager::GetConfigData();

	Add<CTransform>(postition, velocity);
	Get<CTransform>().Scale = Vector2{ (float)config["Bullet"][2], (float)config["Bullet"][2] };

	Add<CCollision>(config["Bullet"][1]);

	Add<CLifeSpan>(config["Bullet"][11]);
	
	Add<CShape>(
		config["Bullet"][0],
		config["Bullet"][10],
		config["Bullet"][9],
		Color{
			(unsigned char)config["Bullet"][3],
			(unsigned char)config["Bullet"][4],
			(unsigned char)config["Bullet"][5],
			255
		},
		Color{
			(unsigned char)config["Bullet"][6],
			(unsigned char)config["Bullet"][7],
			(unsigned char)config["Bullet"][8],
			255
		}
	);
}

void Bullet::Draw() {
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

void Bullet::Update(float deltaTime) {

}