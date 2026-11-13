#pragma once

#include "Component.h"

class CLifeSpan : public Component {
public:
	CLifeSpan() {}
	CLifeSpan(int lifespan) : Lifespan(lifespan), Remaining(lifespan) {}
	int Lifespan = 0;
	int Remaining = 0;
};