#include "Bullet.h"

// Bullet constructor
Bullet::Bullet(const float &xPos) : RectangleShape(Vector2f(BLT_W, BLT_H))
{
	this->speed = BLT_SPEED;

	this->setFillColor(Color::White);

	this->setPosition(xPos, SHIP_YPOS);
}

// Bullet deconstructor
Bullet::~Bullet()
{
	//cout << "Inside ~Bullet()" << endl;
}

// Gets Bullet speed
float Bullet::getSpeed() const
{
	return this->speed;
}

// Bullet think function
void Bullet::think()
{
	this->move(0, -this->getSpeed());
}