#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main()
{
	int worldMap[5][5] =
	{
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,1,0 },
		{ 1,1,1,1,1 },
	};

	int goblinInc = 0, jackieInc = 1, skyInc = 0, goblinDelay = 0, skyDelay = 0, i, j;
	float x, y;
	sf::Sprite walls[5][5];
	
	srand(time(NULL));

	// create the window
	sf::RenderWindow window(sf::VideoMode(500, 500), "Fag & Bawar Software");
	
	sf::Texture goblinTexture;
	goblinTexture.setSmooth(false);
	if (!goblinTexture.loadFromFile("sprites/goblin.png"))
	{
		//error
	}

	sf::Texture jackieTexture;
	jackieTexture.setSmooth(false);
	if (!jackieTexture.loadFromFile("sprites/JackieChan.png"))
	{
		//error
	}

	sf::Texture skyTexture;
	skyTexture.setSmooth(false);
	skyTexture.setRepeated(true);
	if (!skyTexture.loadFromFile("sprites/sky.png"))
	{
		//error
	}

	sf::Sprite goblinSprite;
	goblinSprite.setTexture(goblinTexture);
	goblinSprite.setPosition(sf::Vector2f(400, 350));

	sf::Sprite jackieSprite;
	jackieSprite.setTexture(jackieTexture);
	jackieSprite.setPosition(sf::Vector2f(0, 100));

	sf::Sprite skySprite;
	skySprite.setTexture(skyTexture);
	skySprite.setPosition(sf::Vector2f(0, 198));

	sf::Texture wallTexture;
	wallTexture.setRepeated(false);
	wallTexture.setSmooth(true);
	if (!wallTexture.loadFromFile("sprites/wall.png"))
	{
		//error
	}

	

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (worldMap[i][j] == 1) {
				walls[i][j] = sf::Sprite(wallTexture);
				walls[i][j].setTexture(wallTexture);
				walls[i][j].setTextureRect(sf::IntRect(0, 0, 100, 100));
				walls[i][j].setPosition(sf::Vector2f(j * 100, i * 100));
			}
		}
	}
	
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}


		goblinSprite.setTextureRect(sf::IntRect(goblinInc*65, 195, 70, 60));
		if (goblinDelay == 240)
		{
			goblinDelay = 0;
			if (goblinInc == 6)
				goblinInc = 0;
			else
				goblinInc++;
		}
		else
			goblinDelay++;

		//goblincollision
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				if (goblinSprite.getGlobalBounds().intersects(walls[i][j].getGlobalBounds()))
					goblinSprite.move(sf::Vector2f(0, -0.5));
				else
					goblinSprite.move(sf::Vector2f(0, 0.01));

				if (jackieSprite.getGlobalBounds().intersects(walls[i][j].getGlobalBounds()))
					jackieSprite.move(sf::Vector2f(0, -0.5));
				else
					jackieSprite.move(sf::Vector2f(0, 0.01));
			}
		}
		if (!goblinSprite.getGlobalBounds().intersects(sf::FloatRect(0, 0, 500, 500)))
			goblinSprite.setPosition(sf::Vector2f(400, 350));
		goblinSprite.move(sf::Vector2f(-0.05, 0));

		
		jackieSprite.setTextureRect(sf::IntRect(jackieInc * 50, 2, 50, 72));
		if (jackieInc == 4)
			jackieInc = 1;
		else
			jackieInc++;

		skySprite.setTextureRect(sf::IntRect(skyInc, 218, 500, 202));
		
		if (skyDelay == 120)
		{
			skyDelay = 0;
			if (skyInc == 1020)
				skyInc = 0;
			else
				skyInc++;
		}
		else
			skyDelay++;


		//mouse and random
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//x = rand() % 800;
			//y = rand() % 600;
			x = sf::Mouse::getPosition(window).x-35;
			y = sf::Mouse::getPosition(window).y-25;
			goblinSprite.setPosition(sf::Vector2f(x, y));
		}


		//keyboard controls
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			jackieSprite.move(-0.1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// right key is pressed: move our character
			jackieSprite.move(0.1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// up key is pressed: move our character
			jackieSprite.move(0, -0.5);
		}

		// clear the window with black color
		window.clear(sf::Color(0,104,248));

		// draw everything here...
		window.draw(skySprite);
		window.draw(goblinSprite);
		window.draw(jackieSprite);
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				if (worldMap[i][j] == 1)
					window.draw(walls[i][j]);
			}
		}
		// end the current frame
		window.display();
	}

	return 0;
}