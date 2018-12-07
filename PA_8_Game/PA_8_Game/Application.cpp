#include "Application.h"

World Application::world;
//TileMap Application::tilemap; I think each room will have it's own tilemap and 2d int array
//sf::Texture Application::spriteSheet;
sf::RenderWindow Application::window;

void Application::startGame(void)
{
	/*if (!spriteSheet.loadFromFile("../Resources/Character.png"))
	{
		printf("NOOOO! The spritesheed didn't load!\n");
		exit(0);
	}*/
	window.create(sf::VideoMode(800, 600), "SUPER GAME OF SUPER AWESOME");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
			}

		}

		window.clear();
		world.draw(window); //this should be all we need it should call draw from Room
		window.display();
	}

	
}

World& Application::getWorld()
{
	return world;
}

//sf::Texture& Application::getSpritsheet()
//{
//	return spriteSheet;
//}

sf::RenderWindow& Application::getWindow()
{
	return window;
}