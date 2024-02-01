#pragma once

#include <iostream>
#include <vector>

#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "MainMenu.h"

using std::vector;
using std::to_string;

class Game
{
public:
	Game();
	~Game();

	RenderWindow &getWin();
	MainMenu &getMenu();

	void start();
	void restart();
	void displayPlyLives(float x, float y);
	void displayPlyScore(float x, float y);
	void think();
private:
	double increaseSpawnCD;
	double spawnTime;
	MainMenu menu;
	RenderWindow window;
	Player ply;
	vector<Bullet> blts;
	vector<Asteroid> enemies;
};