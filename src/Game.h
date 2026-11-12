#pragma once

#include <vector>
#include <string>
#include "utils/FileManager.h"

class Game {
public:
	void Init(const std::string& config);
	void Run();
	void Destroy();
private:
	FileManager m_FileManager;
	ConfigMap m_Config;
};