#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "character.h"

class obstacle
{
	friend class character;
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

private:
	int originX;
	int originY;
	int sizeX;
	int sizeY;
};

#endif