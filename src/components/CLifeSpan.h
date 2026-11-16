#pragma once

#include "Component.h"
#include <utils/Timer.h>

class CLifeSpan : public Component {
public:
	CLifeSpan() {}
	CLifeSpan(int lifespan) : Lifespan(lifespan), mTimer((float)lifespan) {}
	int Lifespan = 0;
	Timer mTimer;
};