#pragma once

#include "Component.h"

class CInput : public Component {
public:
	CInput() {}
	bool Up = false;
	bool Down = false;
	bool Left = false;
	bool Right = false;
	bool Shoot = false;
};