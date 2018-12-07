#include "Application.h"

Application::Application ()
{
	cout << "Application constructor called" << endl;
} // end default Application contructor

//TileMap Application::tilemap; I think each room will have it's own tilemap and 2d int array

sf::Texture spriteSheet;

// startGame function
void Application::startGame(void)
{
	World world;
		// load the sprite sheet

	if (!spriteSheet.loadFromFile("../Resources/Hirro.png"))
	{
		printf("NOOOO! The spritesheet didn't load!\n");
		exit(0);
	} // end if spriteSheet loaded correctly
	
	// spriteSheet.loadFromFile("../Resources/Hirro.png");
	
		// create a RenderWindow
	window.create(sf::VideoMode(800, 600), "SUPER GAME OF SUPER AWESOME");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Q)
				{
					window.close ();
				} // end close window if Q
			} // end if keypressed

				// switch for ??
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
			} // end switch

		} // end while window.pollEvent

		window.clear();
		world.draw(window); //this should be all we need, it should call draw from Room
		window.display();
	} // end while window is open

} // end startGame function

World & Application::getWorld()
{
	return world;
}

sf::Texture & Application::getSpritesheet (void)
{
	return spriteSheet;
}

sf::RenderWindow & Application::getWindow()
{
	return window;
}