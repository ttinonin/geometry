#pragma once

#include "Component.h"
#include "utils/CircleShape.h"

class CShape : public Component {
public:
	CShape() {}
	CShape(float radius, float pointCount, float thickness, Color fillColor, Color outlineColor) {
		Circle.SetRadius(radius);
		Circle.SetPointCount(pointCount);
		Circle.SetThickness(thickness);
		Circle.SetOutlineColor(outlineColor);
		Circle.SetFillColor(fillColor);
	}

	CircleShape Circle;
};