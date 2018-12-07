#include "obstacle.h"

// default constructor
obstacle::obstacle ()
{
	originX = 0;
	originY = 0;
	sizeX   = 0;
	sizeY   = 0;
} // end obstacle default constructor

// normal constructor
obstacle::obstacle (int theOriginX, int theOriginY, int theDimX, int theDimY)
{
	originX = theOriginX;
	originY = theOriginY;
	sizeX   = theDimX;
	sizeY   = theDimY;
} // end obstacle normal constructor

// copy constructor
obstacle::obstacle (obstacle &copyObject)
{
	this -> originX = copyObject.originX;
	this -> originY = copyObject.originY;
	this -> sizeX   = copyObject.sizeX;
	this -> sizeY   = copyObject.sizeY;
} // end obstacle copy constructor

// destructor
obstacle::~obstacle ()
{
	// ??
} // end obstacle destructor

	// getters

// getOriginX
int obstacle::getOriginX ()
{
	return originX;
} // end getOriginX

// getOriginY
int obstacle::getOriginY ()
{
	return originY;
} // end getOriginY

// getSizeX
int obstacle::getSizeX ()
{
	return sizeX;
} // end getSizeX

// getSizeY
int obstacle::getSizeY ()
{
	return sizeY;
} // end getSizeY