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

		jackieSprite.setPosition(sf::Vector2f(50, 100));
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

		// end the current frame
		window.display();
	}

	return 0;
}