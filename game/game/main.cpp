#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include <time.h>

int main()
{
	int goblinInc = 0, jackieInc = 1, delay = 0;
	float x, y;
	
	srand(time(NULL));

	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fag & Bawar Software");
	
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

	sf::Sprite jackieSprite;
	jackieSprite.setTexture(jackieTexture);


	sf::Texture circleTexture;
	circleTexture.setRepeated(true);
	circleTexture.setSmooth(true);
	if (!circleTexture.loadFromFile("sprites/wall.png"))
	{
		//error
	}

	sf::CircleShape shape1(5);
	shape1.setPosition(sf::Vector2f(400, 300));
	shape1.setFillColor(sf::Color(100, 250, 50));

	sf::CircleShape shape2(10);
	shape2.setPosition(sf::Vector2f(300, 500));
	shape2.setTexture(&circleTexture);
	shape2.setTextureRect(sf::IntRect(10, 10, 100, 100));

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


		goblinSprite.setTextureRect(sf::IntRect(goblinInc*65, 0, 70, 60));
		if (delay == 120)
		{
			delay = 0;
			if (goblinInc == 6)
				goblinInc = 0;
			else
				goblinInc++;
		}
		else
			delay++;

		jackieSprite.setPosition(sf::Vector2f(0, 100));
		jackieSprite.setTextureRect(sf::IntRect(jackieInc * 50, 2, 50, 72));
		if (jackieInc == 4)
			jackieInc = 1;
		else
			jackieInc++;


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			x = rand() % 800;
			y = rand() % 600;
			shape1.setPosition(sf::Vector2f(x, y));
		}


		// clear the window with black color
		window.clear(sf::Color::White);

		// draw everything here...
		window.draw(goblinSprite);
		window.draw(jackieSprite);
		window.draw(shape1);
		window.draw(shape2);

		// end the current frame
		window.display();
	}

	return 0;
}