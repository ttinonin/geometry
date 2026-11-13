#pragma once

#include <vector>
#include <string>
#include <utils/FileManager.h>
#include "Level.h"

class Game {
public:
	void Init(const std::string& config);
	void Run();
	void Destroy();
private:
	ConfigMap m_Config;
	Level m_Level;
};