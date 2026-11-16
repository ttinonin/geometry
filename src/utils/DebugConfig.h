#pragma once

class DebugConfig {
public:
	static DebugConfig& GetInstance() {
		static DebugConfig instance;
		return instance;
	}

	bool ActiveMovement = true;

	bool ActiveSpawning = true;
	float SpawnInterval = 60.0f;
	bool ManualSpawn = false;

	bool ActiveLifespan = true;
private:
	DebugConfig() = default;
};