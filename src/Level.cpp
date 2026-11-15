#include "Level.h"
#include <imgui.h>

#ifdef _DEBUG
#include <utils/DebugConfig.h>
#endif // _DEBUG


void Level::Init() {
	m_SystemManager.Init(m_EntityManager);
	m_EnemyManager.Init(m_EntityManager);

	auto player = m_EntityManager.AddEntity<Player>();
	player->Init();
	m_EnemyManager.Spawn();

}

void Level::Draw() {
#ifdef _DEBUG
	auto& debug = DebugConfig::GetInstance();

	ImGui::Begin("Geometry");
	if (ImGui::BeginTabBar("Tabbar")) {
		if (ImGui::BeginTabItem("Systems")) {
			ImGui::Checkbox("Movement", &debug.ActiveMovement);
			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Entity Manager"))
		{

			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}
	ImGui::End();
#endif

	for (const auto& entity : m_EntityManager.GetEntities()) {
		entity->Draw();
	}
}

void Level::Update(float deltaTime) {
	m_EntityManager.Update();
	m_SystemManager.Update(deltaTime);
	m_EnemyManager.Update();
}