#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <map>

using ConfigMap = std::map<std::string, std::vector<int>>;

class FileManager {
public:
	void Init(const std::string& path);
	ConfigMap GetConfigData();
private:
	std::ifstream m_Config;
};