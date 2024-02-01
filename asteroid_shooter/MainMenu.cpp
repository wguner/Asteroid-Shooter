#include "MainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{

}

int MainMenu::displayMenu(sf::RenderWindow & window)
{
	displayOverlay(window, _overlaySprite, "images/names.png");
	setBackground(_menuSprite, "images/menu.png", window);


	//displayOverlay(window, _overlaySprite, "images/names.png");
	// Creating Button for Play
	createButton(play, 100, 900, 100, 300, 1);

	// Creating Button for Exit
	createButton(exit, 100, 900, 300, 500, 0);

	return buttonPressed(window);	// if it returns zero, means exit the game, if return 1, means to play the game.
									// this could also be implemented with if statements if you wanted to run the entire
									// program through a menu function

}

void MainMenu::displayOverlay(sf::RenderWindow & window, Sprite overlay, string filename)
{
	Event userEvent;	// learned events from PONG tutorials in gamefromscratch.com
	setBackground(overlay, filename, window);

	do
	{
		while (window.pollEvent(userEvent))
		{
			if (userEvent.type == Event::EventType::KeyPressed || userEvent.type == Event::EventType::MouseButtonPressed)
				return;
		}
	} while (userEvent.type != Event::EventType::KeyPressed || userEvent.type != Event::EventType::MouseButtonPressed);
}

void MainMenu::setBackground(Sprite background, string fileName, sf::RenderWindow & window)
{
	Texture _tBackground;
	_tBackground.loadFromFile(fileName);
	background.setTexture(_tBackground);
	window.draw(background);
	window.display();
}

void MainMenu::createButton(Rect<int> button, int xLeftPixelLevel, int xRightPixelLevel, int yTopPixelLevel, int yBottomPixelLevel, int levelOfButton)
{
	button.top = yTopPixelLevel;
	button.height = yBottomPixelLevel;
	button.left = xLeftPixelLevel;
	button.width = xRightPixelLevel;

	pair<Rect<int>, int> newPair(button, levelOfButton);

	_buttonPairs.push_back(newPair);
}

int MainMenu::buttonPressed(sf::RenderWindow & mainWindow)
{
	int returnValue = 0;
	Event tempEvent;
	list<pair<Rect<int>, int>>::iterator num;	// learned iterators from gamefromscratch.com PONG game

	do
	{
		while (mainWindow.pollEvent(tempEvent))
		{
			if (tempEvent.type == Event::Closed)
				return 0;	// means exit game
			else if (tempEvent.type == Event::MouseButtonPressed)
			{
				num = _buttonPairs.begin();
				while (num != _buttonPairs.end())
				{
					if (((*num).first.left < tempEvent.mouseButton.x) && ((*num).first.width > tempEvent.mouseButton.x) && ((*num).first.top < tempEvent.mouseButton.y) && ((*num).first.height > tempEvent.mouseButton.y))
					{
						return (*num).second;
					}
					num++;
				}
			}
		}
	} while (tempEvent.type != Event::MouseButtonPressed || tempEvent.type != Event::Closed);	// will continue running unless mouse button is pressed closed window
	return returnValue;
}