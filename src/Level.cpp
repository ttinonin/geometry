#include "Level.h"
#include <imgui.h>

#ifdef _DEBUG
#include <utils/DebugConfig.h>
#endif // _DEBUG


void Level::Init() {
	m_SystemManager.Init(m_EntityManager);
	m_EnemyManager.Init(m_EntityManager);
	m_BulletManager.Init(m_EntityManager);

	auto player = m_EntityManager.AddEntity<Player>();
	player->Init();
}

void Level::Draw() {
#ifdef _DEBUG
	auto& debug = DebugConfig::GetInstance();

	ImGui::Begin("Geometry");
	if (ImGui::BeginTabBar("Tabbar")) {
		if (ImGui::BeginTabItem("Systems")) {
			ImGui::Checkbox("Lifespan", &debug.ActiveLifespan);

			ImGui::Checkbox("Movement", &debug.ActiveMovement);
			
			ImGui::Checkbox("Spawning", &debug.ActiveSpawning);
			ImGui::Indent();
			ImGui::SliderFloat("Spawn Interval", &debug.SpawnInterval, 1.0f, 100.0f);
			if (ImGui::Button("Manual Spawn")) {
				debug.ManualSpawn = true;
			}
			ImGui::Unindent();

			ImGui::EndTabItem();
		}

		if (ImGui::BeginTabItem("Entity Manager"))
		{
			if(ImGui::TreeNode("Entities by Tag")) {
				for (auto& [tag, entities] : m_EntityManager.GetEntitiesTags()) {
					if (ImGui::TreeNode(tag.c_str())) {
						for (auto& entity : entities) {
							if (ImGui::SmallButton("D")) {
								entity->Destroy();
							}

							ImGui::SameLine();

							auto& transform = entity->Get<CTransform>();
							ImGui::Text("%d %s (%d, %d)", entity->GetId(), tag.c_str(), (int)transform.Position.x, (int)transform.Position.y);
						}

						ImGui::TreePop();
					}
				}
				ImGui::TreePop();
			}

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
	m_EnemyManager.Update(deltaTime);
	m_BulletManager.Update(deltaTime);
}