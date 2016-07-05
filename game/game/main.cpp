#include <SFML/Graphics.hpp>

int main()
{
	int goblinInc = 0, jackieInc = 1;



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

	sf::CircleShape shape1(50);
	shape1.setPosition(sf::Vector2f(200, 500));
	shape1.setFillColor(sf::Color(100, 250, 50));

	sf::CircleShape shape2(50);
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
		if (goblinInc == 7)
			goblinInc = 0;
		else
			goblinInc++;

		jackieSprite.setPosition(sf::Vector2f(0, 100));
		jackieSprite.setTextureRect(sf::IntRect(jackieInc * 50, 2, 50, 72));
		if (jackieInc == 4)
			jackieInc = 1;
		else
			jackieInc++;

		// clear the window with black color
		window.clear(sf::Color::Black);

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