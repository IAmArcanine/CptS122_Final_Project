#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using std::cout;
using std::endl;

class obstacle;

class character
{
	friend class obstacle;

public:
		// move functions:

	void move_left  (sf::Sprite *theSprite, sf::Texture *theTexture);
	void move_right (sf::Sprite *theSprite, sf::Texture *theTexture);
	void move_up    (sf::Sprite *theSprite, sf::Texture *theTexture);
	void move_down  (sf::Sprite *theSprite, sf::Texture *theTexture);
	
		// check position functions
	bool check_left  (sf::Sprite theSprite, sf::Sprite theObstacle);
	bool check_right (sf::Sprite theSprite, sf::Sprite theObstacle);
	bool check_up    (sf::Sprite theSprite, sf::Sprite theObstacle);
	bool check_down  (sf::Sprite theSprite, sf::Sprite theObstacle);

private:
};

#endif