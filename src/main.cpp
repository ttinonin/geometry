#include "Game.h"

int main() {
	Game game;

	game.Init(RESOURCES_PATH"config.txt");

	game.Run();

	game.Destroy();

	return 0;
}