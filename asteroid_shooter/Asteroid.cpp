#include "Asteroid.h"

// Asteroid default constructor
Asteroid::Asteroid() : CircleShape(AST_SIZE_BIG),
	radius(AST_SIZE_BIG), speed(AST_SPEED)
{
	this->setOutlineColor(Color::White);
	this->setFillColor(Color::Black);
	this->setOutlineThickness(3);

	int randomX = (std::rand() % (WIN_W - AST_SIZE_BIG)) + 1;
	this->setPosition((float)randomX, 0);
}

// Asteroid constructor
Asteroid::Asteroid(float radius) : CircleShape(radius), // random num 15-30
	radius(radius), speed(AST_SPEED)
{
	this->setOutlineColor(Color::White);
	this->setFillColor(Color::Black);
	this->setOutlineThickness(3);

	int randomX = (std::rand() % WIN_W) + 1;
	this->setPosition((float)randomX, 0);
}

// Asteroid destructor
Asteroid::~Asteroid()
{
	//cout << "Inside ~Asteroid()" << endl;
}

// Gets Asteroid speed
float Asteroid::getSpeed() const
{
	return this->speed;
}

// Sets Asteroid direction
void Asteroid::setDir(const string &dir)
{
	this->dir = dir;
}

// Gets Asteroid direction
string Asteroid::getDir() const
{
	return this->dir;
}

// Sets Asteroid radius
void Asteroid::setRadius(const float radius)
{
	this->radius = radius;
}

// Gets Asteroid radius
float Asteroid::getRadius() const
{
	return this->radius;
}

// Called when an Asteroid is hit
void Asteroid::hit(vector<Asteroid> &enemies, int i)
{
	if (this->radius == AST_SIZE_BIG)
	{
		float x = enemies[i].getPosition().x, y = enemies[i].getPosition().y;
		enemies.erase(enemies.begin() + i);

		enemies.push_back(Asteroid(AST_SIZE_SML));
		enemies.back().setDir("left");
		enemies.back().setPosition(x - 30, y + 15);
		enemies.push_back(Asteroid(AST_SIZE_SML));
		enemies.back().setDir("right");
		enemies.back().setPosition(x + 30, y + 15);
	}
	else
	{
		enemies.erase(enemies.begin() + i);
	}
}

// Asteroid think function
void Asteroid::think()
{
	if (this->getRadius() == AST_SIZE_BIG)
	{
		this->move(0, this->getSpeed());
	}
	else if (this->dir == "left")
	{
		this->move(-this->getSpeed() / 1.5, this->getSpeed() / 1.5);
		
		if (this->getPosition().x <= 0)
			this->setDir("right");
	}
	else if (this->dir == "right")
	{
		this->move(this->getSpeed() / 1.5, this->getSpeed() / 1.5);

		if (this->getPosition().x >= WIN_W - AST_SIZE_SML)
			this->setDir("left");
	}
}