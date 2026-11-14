#include "Game.h"
#include <fstream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

void Game::Init(const std::string& config) {
	m_Config = FileManager::GetConfigDataFromFile(config);
	
	if (m_Config["Window"][3] == 1) {
		SetConfigFlags(FLAG_FULLSCREEN_MODE);
	}

	InitWindow(m_Config["Window"][0], m_Config["Window"][1], "Geometry");
	SetTargetFPS(m_Config["Window"][2]);

	rlImGuiSetup(true);

	m_Level.Init();
}

void Game::Run() {
	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();
		
		m_Level.Update(deltaTime);
		
		BeginDrawing();
		ClearBackground(BLACK);
		rlImGuiBegin();
		
		m_Level.Draw();

		rlImGuiEnd();
		EndDrawing();
	}
}

void Game::Destroy() {
	rlImGuiShutdown();
	CloseWindow();
}