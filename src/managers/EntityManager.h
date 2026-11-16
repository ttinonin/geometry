#pragma once

#include <vector>
#include <memory>
#include <entities/Entity.h>
#include <map>
#include <string>

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager {
private:
	EntityVec m_Entities;
	EntityVec m_ToAdd;
	EntityMap m_EntityMap;
	size_t m_TotalEntities = 0;
public:
	EntityManager() {}
	void Update();

	template<typename T, typename... Args>
	std::shared_ptr<T> AddEntity(Args&&... args) {
		auto entity = std::make_shared<T>(
			m_TotalEntities++,
			std::forward<Args>(args)...
		);

		m_ToAdd.push_back(entity);
		return entity;
	}

	EntityVec& GetEntities() { return m_Entities; };
	EntityVec& GetEntities(const std::string& tag) { return m_EntityMap[tag]; };
	EntityMap& GetEntitiesTags() { return m_EntityMap; }
};