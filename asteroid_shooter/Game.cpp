#include "Game.h"

// Game constructor
Game::Game()
{
	this->window.create(VideoMode(WIN_W, WIN_H, 32), "Asteroid Shooter");
	this->window.setFramerateLimit(WIN_FRAMERATE); // https://en.sfml-dev.org/forums/index.php?topic=5922.0
	this->ply = Player();
	this->spawnTime = (clock() / (double)CLOCKS_PER_SEC) + 2;
	this->increaseSpawnCD = (clock() / (double)CLOCKS_PER_SEC) + AST_DECREASE_SPAWN_TIME;
	this->menu = MainMenu();
}

// Game deconstructor
Game::~Game()
{
	//cout << "Inside ~Game()" << endl;
}

// Gets Game window
RenderWindow &Game::getWin()
{
	return this->window;
}

// Gets Game menu
MainMenu &Game::getMenu()
{
	return this->menu;
}

double spawnInterval = (double)AST_SPAWN_TIME; // I know this is sloppy, in a timecrunch

// Starts Game round
void Game::start()
{
	if (this->getMenu().displayMenu(this->getWin()) == 1)
	{
		this->ply.setLives(PLY_LIVES);
		this->ply.setScore(0);

		while (this->getWin().isOpen() && this->ply.getLives() != 0)
			this->think();
	}
}

// ReStarts Game round
void Game::restart()
{
	this->spawnTime = clock() / (double)CLOCKS_PER_SEC;
	this->increaseSpawnCD = clock() / (double)CLOCKS_PER_SEC;
	this->blts.clear();
	this->enemies.clear();
	this->ply.setPosition((WIN_W / 2) - (SHIP_SIZE), SHIP_YPOS);
	spawnInterval = (double)AST_SPAWN_TIME;
}

// Displays Player lives
void Game::displayPlyLives(float x, float y)
{
	Font font;
	font.loadFromFile("fonts/Roboto-Medium.ttf");

	Text lives;
	lives.setString("Lives Left: " + to_string(this->ply.getLives()));
	lives.setFont(font);
	lives.setCharacterSize(20);
	lives.setFillColor(Color::White);
	lives.setPosition(x, y); 

	this->getWin().draw(lives);
}

// Displays Player score
void Game::displayPlyScore(float x, float y)
{
	Font font;
	font.loadFromFile("fonts/Roboto-Medium.ttf");

	Text lives;
	lives.setString("Score: " + to_string(this->ply.getScore()));
	lives.setFont(font);
	lives.setCharacterSize(20);
	lives.setFillColor(Color::White);
	lives.setPosition(x, y);

	this->getWin().draw(lives);
}

// Think function for Game
void Game::think()
{
	Event event;
	clock_t now = clock();

	if (now / (double)CLOCKS_PER_SEC >= this->increaseSpawnCD)
	{
		this->increaseSpawnCD += (double)AST_DECREASE_SPAWN_TIME;

		if (spawnInterval > 1)
			spawnInterval -= 0.5;
	}

	if (now / (double)CLOCKS_PER_SEC >= this->spawnTime)
	{
		this->enemies.push_back(Asteroid(AST_SIZE_BIG));
		this->spawnTime += spawnInterval;
	}

	while (this->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			this->window.close();
	}

	// Think functions
	this->ply.think(this->blts);

	for (unsigned int i = 0; i < this->blts.size(); i++)
	{
		this->blts[i].think();

		for (unsigned int n = 0; n < this->enemies.size(); n++)
		{
			if (this->blts[i].getGlobalBounds().intersects(this->enemies[n].getGlobalBounds()))
			{
				this->enemies[n].hit(this->enemies, n);
				this->ply.addScore();
			}
		}

		if (this->blts[i].getPosition().y <= -BLT_H)
			this->blts.erase(this->blts.begin()); // http://www.cplusplus.com/reference/vector/vector/erase/
	}

	for (unsigned int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].think();

		if (this->enemies[i].getPosition().y >= WIN_H) // Asteroid got through
		{
			this->ply.removeLife();
			this->restart();
			
			if (this->ply.getLives() == 0)
				this->start();

			return;
		}
	}

	this->window.clear();
	
	this->window.draw(this->ply);
	for (unsigned int i = 0; i < this->blts.size(); i++)
		this->window.draw(this->blts[i]);
	for (unsigned int i = 0; i < this->enemies.size(); i++)
		this->window.draw(this->enemies[i]);

	this->displayPlyLives(13, 5);
	this->displayPlyScore(13, 27);

	this->window.display();
}