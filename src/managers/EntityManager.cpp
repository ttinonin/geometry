#include "EntityManager.h"
#include <algorithm>

void EntityManager::Update() {
	for (auto e : m_ToAdd) {
		m_Entities.push_back(e);
		m_EntityMap[e->GetTag()].push_back(e);
	}
	m_Entities.erase(
		std::remove_if(
			m_Entities.begin(),
			m_Entities.end(),
			[](const std::shared_ptr<Entity>& entity) {
				return !entity->IsAlive();
			}
		),
		m_Entities.end()
	);
	m_ToAdd.clear();
}