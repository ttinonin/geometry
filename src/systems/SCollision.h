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
};