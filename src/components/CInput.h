#pragma once

#include "Component.h"

class CInput : public Component {
public:
	CInput() {}
	int Up = 0;
	int Down = 0;
	int Left = 0;
	int Right = 0;
	int Shoot = 0;
};