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

	int goblinInc = 0, jackieInc = 1, delay = 0, i, j;
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

	sf::Sprite goblinSprite;
	goblinSprite.setTexture(goblinTexture);
	goblinSprite.setPosition(sf::Vector2f(400, 350));

	sf::Sprite jackieSprite;
	jackieSprite.setTexture(jackieTexture);
	jackieSprite.setPosition(sf::Vector2f(0, 100));

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
		if (delay == 240)
		{
			delay = 0;
			if (goblinInc == 6)
				goblinInc = 0;
			else
				goblinInc++;
		}
		else
			delay++;

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

		//mouse and random
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			//x = rand() % 800;
			//y = rand() % 600;
			x = sf::Mouse::getPosition(window).x-35;
			y = sf::Mouse::getPosition(window).y-25;
			goblinSprite.setPosition(sf::Vector2f(x, y));
		}


		// clear the window with black color
		window.clear(sf::Color::White);

		// draw everything here...
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