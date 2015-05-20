#include "Game.h"
#include <iostream>
#define EXIT_SUCCESS 0

int main(int argc, char** args) {
	Game game(640, 480);

	game.run();

	return EXIT_SUCCESS;
}
