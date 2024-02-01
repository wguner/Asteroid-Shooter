#include "Player.h"

// Player constructor
Player::Player() : Ship(SHIP_PTCOUNT)
{
	this->lives = PLY_LIVES;
	this->score = 0;
	this->setPosition((WIN_W / 2) - (SHIP_SIZE / 2), SHIP_YPOS);
}

// Player deconstructor
Player::~Player()
{
	//cout << "Inside ~Player()" << endl;
}

// Adds one score to player
void Player::addScore()
{
	this->score++;
}

// Sets Player score
void Player::setScore(const unsigned int score)
{
	this->score = score;
}

// Gets Player score
unsigned int Player::getScore() const
{
	return this->score;
}

// Removes a life from Player
void Player::removeLife()
{
	this->lives--;
}

// Sets Player lives
void Player::setLives(const unsigned int lives)
{
	this->lives = lives;
}

// Gets Player lives left
unsigned int Player::getLives() const
{
	return this->lives;
}