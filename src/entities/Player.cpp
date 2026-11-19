#include "Player.h"
#include <utils/FileManager.h>

void Player::Init() {
	ConfigMap config = FileManager::GetConfigData();

	Add<CShape>(
		config["Player"][0],
		(float)config["Player"][10],
		(float)config["Player"][9],
		Color{ static_cast<unsigned char>(config["Player"][3]), static_cast<unsigned char>(config["Player"][4]), static_cast<unsigned char>(config["Player"][5]), 255 },
		Color{ static_cast<unsigned char>(config["Player"][6]), static_cast<unsigned char>(config["Player"][7]), static_cast<unsigned char>(config["Player"][8]), 255 }
	);

	Add<CTransform>(Vector2{ 30.0f, 30.0f }, Vector2{0.0f, 0.0f});
	Get<CTransform>().Scale.x = (float)config["Player"][2];
	Get<CTransform>().Scale.y = (float)config["Player"][2];

	Add<CInput>();

	Add<CCollision>((float)config["Player"][0]);

	Add<CScore>();
}

void Player::Update(float deltaTime) {

}

void Player::Draw() {
	auto& shape = Get<CShape>();
	auto& transform = Get<CTransform>();
	auto& score = Get<CScore>();

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

	DrawText(TextFormat("SCORE: %d", score.Score), 0, 0, 20, WHITE);
}