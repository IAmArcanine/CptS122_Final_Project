#pragma once
#include "Background.h"
#include "World.h"


	// enumerated type for character movement:
class Application
{
public:
		// default constructor
	Application ();

		// functions
	void startGame       (void);
	World &getWorld       (void);
	sf::RenderWindow &getWindow      (void);
	sf::Texture &getSpritesheet (void);

private:
	World world;
	sf::RenderWindow window;
};
