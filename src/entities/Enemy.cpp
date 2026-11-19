#include "Enemy.h"
#include <utils/FileManager.h>
#include <raylib.h>

void Enemy::Init() {
	ConfigMap config = FileManager::GetConfigData();
	float angle = (float)GetRandomValue(0, 359) * DEG2RAD;

	Vector2 direction = {
		cosf(angle),
		sinf(angle)
	};

	Add<CTransform>(Vector2{ (float)GetRandomValue(config["Enemy"][0], config["Window"][0] - config["Enemy"][0]), (float)GetRandomValue(config["Enemy"][0], config["Window"][1] - config["Enemy"][0]) }, direction);
	Get<CTransform>().Scale = Vector2{ (float)GetRandomValue(config["Enemy"][2], config["Enemy"][3]), (float)GetRandomValue(config["Enemy"][2], config["Enemy"][3]) };

	Add<CCollision>((float)config["Enemy"][0]);
	
	Color randomColor = {
	(unsigned char)GetRandomValue(0, 255),
	(unsigned char)GetRandomValue(0, 255),
	(unsigned char)GetRandomValue(0, 255),
	255
	};

	Add<CShape>(
		config["Enemy"][0],
		(float)GetRandomValue(config["Enemy"][8], config["Enemy"][9]),
		(float)config["Enemy"][7],
		randomColor,
		Color{ static_cast<unsigned char>(config["Enemy"][4]), static_cast<unsigned char>(config["Enemy"][5]), static_cast<unsigned char>(config["Enemy"][6]), 255 }
	);
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