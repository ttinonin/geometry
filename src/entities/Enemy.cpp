#include "Enemy.h"
#include <utils/FileManager.h>
#include <raylib.h>

void Enemy::Init() {
	ConfigMap config = FileManager::GetConfigData();
	Add<CTransform>(Vector2{ (float)GetRandomValue(0, config["Window"][0]), (float)GetRandomValue(0, config["Window"][1]) }, Vector2{1.0f,1.0f});

	Add<CShape>();
	Get<CShape>().Circle.SetRadius(config["Enemy"][0]);
	Get<CShape>().Circle.SetPointCount((float)GetRandomValue(config["Enemy"][8], config["Enemy"][9]));
	Get<CShape>().Circle.SetThickness((float)config["Enemy"][7]);
	Get<CShape>().Circle.SetOutlineColor(Color{ static_cast<unsigned char>(config["Enemy"][4]), static_cast<unsigned char>(config["Enemy"][5]), static_cast<unsigned char>(config["Enemy"][6]), 255 });
	
	Color randomColor = {
	(unsigned char)GetRandomValue(0, 255),
	(unsigned char)GetRandomValue(0, 255),
	(unsigned char)GetRandomValue(0, 255),
	255
	};

	Get<CShape>().Circle.SetFillColor(randomColor);
}

void Enemy::Draw() {
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

void Enemy::Update(float deltaTime) {

}