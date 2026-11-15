#pragma once

class DebugConfig {
public:
	static DebugConfig& GetInstance() {
		static DebugConfig instance;
		return instance;
	}

	bool ActiveMovement = true;
private:
	DebugConfig() = default;
};