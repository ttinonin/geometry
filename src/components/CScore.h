#pragma once

#include "Component.h"

class CScore : public Component {
public:
	CScore() {}

	void Increment(int amount) {
		Score += amount;
	}

	void Decrement(int amount) {
		if (Score - amount <= 0) {
			Score = 0;
			return;
		}

		Score -= amount;
	}
	int Score = 0;
};