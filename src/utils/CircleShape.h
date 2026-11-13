#pragma once

#include <raylib.h>

class CircleShape {
public:
	CircleShape() = default;
	CircleShape(float radius, int pointCount) : m_Radius(radius), m_PointCount(pointCount) {};

	void SetRadius(float radius) { m_Radius = radius; };
	float GetRadius() const { return m_Radius; };

	void SetPointCount(int pointCount) { m_PointCount = pointCount; };
	int GetPointCount() const { return m_PointCount; };

	void SetThickness(float thickness) { m_Thickness = thickness; };
	float GetThickness() const { return m_Thickness; };

	void SetRotation(float rotation) { m_Rotation = rotation; };
	float GetRotation() const { return m_Rotation; };

	void SetOutlineColor(Color color) { m_OutlineColor = color; };
	Color GetOutlineColor() const { return m_OutlineColor; };

	void SetFillColor(Color color) { m_FillColor = color; };
	Color GetFillColor() const { return m_FillColor; };
private:
	/*Vector2 m_Position = {};
	float m_Radius = 0.0f;
	float m_PointCount = 0.0f;
	float m_Rotation = 0.0f;
	float m_Thickness = 0.0f;
	Color m_FillColor = {};
	Color m_OutlineColor = {};*/

	float m_Radius = 32.0f;
	float m_PointCount = 8;
	float m_Rotation = 0.0f;
	float m_Thickness = 4.0f;
	Color m_FillColor = {};
	Color m_OutlineColor = {255,0,0,255};
};