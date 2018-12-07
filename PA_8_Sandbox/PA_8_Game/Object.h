#pragma once
#include "Application.h"

class Object
{
public:
		// default constructor
	Object();

		// initialized constructor 1
	Object(int x1, int x2, int y1, int y2);
	
		// initialized constructor 2
	Object(sf::IntRect &location);
	
	// sf::Sprite &getSprite(void);
	
		// getter

	sf::IntRect getLocation(void);
	
		// functions

protected:
	//sf::Texture texture; This is not needed. The texture will be part of the sprite
	//sf::Sprite mSprite;
	//because textures are a part of the map, and walls along the side are a type of object
	sf::IntRect mLocation;
};
// will move to its own header if 
