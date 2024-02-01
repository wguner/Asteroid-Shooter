#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Settings.h"

using namespace sf;
using std::cout;
using std::endl;
using std::vector;

class Bullet : public RectangleShape
{
public:
	Bullet(const float &xPos);
	~Bullet();

	float getSpeed() const;

	void think();
private:
	float speed;
};