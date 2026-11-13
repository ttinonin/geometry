#include "Game.h"
#include <fstream>
#include <iostream>
#include <raylib.h>


void Game::Init(const std::string& config) {
	m_Config = FileManager::GetConfigData(config);
	
	if (m_Config["Window"][3] == 1) {
		SetConfigFlags(FLAG_FULLSCREEN_MODE);
	}

	InitWindow(m_Config["Window"][0], m_Config["Window"][1], "Geometry");
	SetTargetFPS(m_Config["Window"][2]);

	m_Level.Init();
}

void Game::Run() {
	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();
		
		m_Level.Update(deltaTime);
		
		BeginDrawing();
		ClearBackground(BLACK);

		m_Level.Draw();

		EndDrawing();
	}
}

void Game::Destroy() {
	CloseWindow();
}