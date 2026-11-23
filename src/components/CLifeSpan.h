#pragma once

#include "Component.h"
#include <utils/Timer.h>

class CLifeSpan : public Component {
public:
	CLifeSpan() {}
	CLifeSpan(int lifespan) : Lifespan(lifespan), mTimer((float)lifespan) {}
	float Lifespan = 0.0f;
	Timer mTimer;
};