#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "character.h"

class obstacle
{
	friend class character;
	friend class obstacleSet;
public:
		// default constructor
	obstacle ();
		// normal constructor
	obstacle (int theOriginX, int theOriginY, int theDimX, int theDimY);
		// copy constructor
	obstacle (obstacle &copyObject);
		// destructor
	~obstacle ();

		// getters
	int getOriginX ();
	int getOriginY ();
	int getSizeX   ();
	int getSizeY   ();
	sf::Sprite* getSprite();

private:
	int originX;
	int originY;
	int sizeX;
	int sizeY;
	sf::FloatRect collisionZone;
};

#endif