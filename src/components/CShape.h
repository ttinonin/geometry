#pragma once

#include "Component.h"
#include "utils/CircleShape.h"

class CShape : public Component {
public:
	CShape() {}
	CircleShape Circle;
};