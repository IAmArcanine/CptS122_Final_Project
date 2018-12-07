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
	character();
		// move functions:
		// check position functions
	bool check_left  (sf::Sprite theSprite, obstacle* theObstacle, int nObstacles);
	bool check_right (sf::Sprite theSprite, obstacle* theObstacle, int nObstacles);
	bool check_up    (sf::Sprite theSprite, obstacle* theObstacle, int nObstacles);
	bool check_down  (sf::Sprite theSprite, obstacle* theObstacle, int nObstacles);

private:
};

#endif