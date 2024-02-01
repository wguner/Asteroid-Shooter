#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Settings.h"

using namespace sf;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Asteroid : public CircleShape
{
public:
	Asteroid();
	Asteroid(const float radius = AST_SIZE_BIG);
	~Asteroid();

	float getSpeed() const;
	void setDir(const string &dir);
	string getDir() const;
	void setRadius(const float radius);
	float getRadius() const;
	void hit(vector<Asteroid> &enemies, int i);

	void think();
private:
	float radius;
	float speed;
	string dir;
};