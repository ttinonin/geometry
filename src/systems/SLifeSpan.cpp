#include "SLifeSpan.h"
#include <components/CLifeSpan.h>

#ifdef _DEBUG
#include <utils/DebugConfig.h>
#endif // _DEBUG

void SLifeSpan::Update(EntityManager& entityManager, float deltaTime) {
#ifdef _DEBUG
	auto& debug = DebugConfig::GetInstance();
	if (!debug.ActiveLifespan) return;

	for (auto& entity : entityManager.GetEntities()) {
		if (!entity->Has<CLifeSpan>()) continue;

		auto& lifespan = entity->Get<CLifeSpan>();

		lifespan.mTimer.Update(deltaTime);

		if (lifespan.mTimer.IsFinished()) {
			entity->Destroy();
		}
	}
#else
	for (auto& entity : entityManager.GetEntities()) {
		if (!entity->Has<CLifeSpan>()) continue;

		auto& lifespan = entity->Get<CLifeSpan>();

		lifespan.mTimer.Update(deltaTime);

		if (lifespan.mTimer.IsFinished()) {
			entity->Destroy();
		}
	}
#endif // _DEBUG

	
}