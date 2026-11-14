#include "Level.h"
#include <imgui.h>

void Level::Init() {
	m_SystemManager.Init(m_EntityManager);

	auto player = m_EntityManager.AddEntity<Player>();
	player->Init();
}

void Level::Draw() {
	ImGui::Begin("Geometry");
	if (ImGui::BeginTabBar("Tabbar")) {
		if (ImGui::BeginTabItem("Systems")) {
			ImGui::Text("General settings go here.");
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Audio"))
		{
			ImGui::Text("Audio controls go here.");
			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}
	ImGui::End();

	for (const auto& entity : m_EntityManager.GetEntities()) {
		entity->Draw();
	}
}

void Level::Update(float deltaTime) {
	m_EntityManager.Update();
	m_SystemManager.Update(deltaTime);
}