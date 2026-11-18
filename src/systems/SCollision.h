#pragma once

#include <managers/EntityManager.h>
#include <string>

class SCollision {
public:
	void Update(EntityManager& entityManager, float deltaTime);
private:
	bool IsCollisionPair(
		const std::string& tagA,
		const std::string& tagB,
		const std::string& first,
		const std::string& second
	) {
		return (tagA == first && tagB == second) ||
			(tagA == second && tagB == first);
	}

	std::shared_ptr<Entity> GetEntityByTag(
		const std::shared_ptr<Entity>& a,
		const std::shared_ptr<Entity>& b,
		const std::string& tag
	) {
		return a->GetTag() == tag ? a : b;
	}
};