#include "EntityManager.h"
#include <algorithm>
#include <iostream>

void EntityManager::Update() {
    for (auto& e : m_ToAdd) {
        m_Entities.push_back(e);
        m_EntityMap[e->GetTag()].push_back(e);
    }

    auto isDead = [](const std::shared_ptr<Entity>& entity) {
        return !entity->IsAlive();
        };

    m_Entities.erase(
        std::remove_if(m_Entities.begin(), m_Entities.end(), isDead),
        m_Entities.end()
    );

    for (auto& [tag, entities] : m_EntityMap) {
        entities.erase(
            std::remove_if(entities.begin(), entities.end(), isDead),
            entities.end()
        );
    }

    m_ToAdd.clear();
}