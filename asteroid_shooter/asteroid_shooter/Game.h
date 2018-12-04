#pragma once

#include <iostream>
#include <vector>

#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"

using std::vector;

class Game
{
public:
	Game();
	~Game();

	RenderWindow &getWin();

	void startRound();
	void endRound();
	void think();

	bool isCollide(Game *first, Game *second)
	{
		return (second->x - first->x)*(second->x - first->x) + (second->y - first ->y)*
			(second ->y - first->y)<(first->radius + second->radius)*(first->radius + second->radius);
	}
	/*
	circle.setPosition(x, y);
	circle.setOrigin(rad, rad);

	if (first == "Asteroid" && second == "Bullet")
		if (isCollide(first, second)){
			first->life = life - 1;
			second->life = life - 1;

	if (first == "Player" && second == "Asteroid")
		if (isCollide(a, b)){
			b->life = life - 1;
	*/

private:
	float x, y, radius;
	RenderWindow window;
	Player ply;
	vector<Bullet> blts;
	vector<Asteroid> enemies;
};
