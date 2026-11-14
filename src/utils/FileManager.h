#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <map>

using ConfigMap = std::map<std::string, std::vector<int>>;

class FileManager {
public:
	static ConfigMap GetConfigDataFromFile(const std::string& path);
	static ConfigMap GetConfigData();
	static ConfigMap Config;
};