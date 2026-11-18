#include "SLifeSpan.h"
#include <components/CLifeSpan.h>

#ifdef _DEBUG
#include <utils/DebugConfig.h>
#endif // _DEBUG

void SLifeSpan::FadeOut(const std::shared_ptr<Entity>& entity) {
	auto& lifespan = entity->Get<CLifeSpan>();

	float progress = lifespan.mTimer.GetRemaining() /
		lifespan.mTimer.GetDuration();

	unsigned char alpha = static_cast<unsigned char>(progress * 255);

	auto& shape = entity->Get<CShape>();

	Color fill = shape.Circle.GetFillColor();
	Color outline = shape.Circle.GetOutlineColor();

	fill.a = alpha;
	outline.a = alpha;

	shape.Circle.SetFillColor(fill);
	shape.Circle.SetOutlineColor(outline);
}

void SLifeSpan::Update(EntityManager& entityManager, float deltaTime) {
#ifdef _DEBUG
	auto& debug = DebugConfig::GetInstance();
	if (!debug.ActiveLifespan) return;

	for (auto& entity : entityManager.GetEntities()) {
		if (!entity->Has<CLifeSpan>()) continue;

		if (entity->Has<CShape>()) {
			FadeOut(entity);
		}

		auto& lifespan = entity->Get<CLifeSpan>();

		lifespan.mTimer.Update(deltaTime);

		if (lifespan.mTimer.IsFinished()) {
			entity->Destroy();
		}
	}
#else
	for (auto& entity : entityManager.GetEntities()) {
		if (!entity->Has<CLifeSpan>()) continue;

		if (entity->Has<CShape>()) {
			FadeOut(entity);
		}

		auto& lifespan = entity->Get<CLifeSpan>();

		lifespan.mTimer.Update(deltaTime);

		if (lifespan.mTimer.IsFinished()) {
			entity->Destroy();
		}
	}
#endif // _DEBUG

	
}