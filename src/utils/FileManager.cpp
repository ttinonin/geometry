#include "FileManager.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

ConfigMap FileManager::GetConfigData(const std::string& path) {
	std::ifstream file(path);
	if (!file.is_open()) {
		throw std::runtime_error("Couldn't open the config file");
	}

	ConfigMap config;
	std::string line;

	while (std::getline(file, line)) {
		std::vector<int> result;
		int currentWord = 0;
		std::stringstream ss(line);
		std::string keyWord;
		std::string item;
		while (std::getline(ss, item, ' ')) {
			if (currentWord == 0) {
				keyWord = item;
				currentWord++;
				continue;
			}
			result.push_back(std::stoi(item));
		}
		config[keyWord] = result;
	}

	return config;
}