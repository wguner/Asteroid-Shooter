#pragma once

#include "Game.h"

int main()
{
	std::srand(std::time(nullptr));
	
	Game game;
	game.start();

	return EXIT_SUCCESS;
}