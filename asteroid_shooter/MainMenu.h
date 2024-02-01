#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <list>

using sf::Event;
using sf::Rect;
using sf::Sprite;
using sf::Texture;
using std::list;
using std::pair;
using std::string;

class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	int displayMenu(sf::RenderWindow & window);
	void displayOverlay(sf::RenderWindow & window, Sprite overlay, string filename);
	void setBackground(Sprite background, string fileName, sf::RenderWindow & window);
	void createButton(Rect<int> button, int xLeftPixelLevel, int xRightPixelLevel, int yTopPixelLevel, int yBottomPixelLevel, int levelOfButton);
	int buttonPressed(sf::RenderWindow & window);

private:
	Rect<int> play;
	Rect<int> exit;
	Sprite _menuSprite;
	Sprite _overlaySprite;

	list<pair<Rect<int>, int>> _buttonPairs;
};