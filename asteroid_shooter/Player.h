#pragma once

#include "Ship.h"

class Player : public Ship
{
public:
	Player();
	~Player();

	void addScore();
	void setScore(const unsigned int score);
	unsigned int getScore() const;

	void removeLife();
	void setLives(const unsigned int lives);
	unsigned int getLives() const;
private:
	unsigned int lives;
	unsigned int score;
};