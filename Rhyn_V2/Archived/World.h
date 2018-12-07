#ifndef WORLD_H
#define WORLD_H

#define _CRT_SECURE_NO_WARNINGS

#include "Room.h"

class World
{
public:
		// default constructor
	World ();

		// initialized constructor
	World (string filePath);

		// copy constructor
	World (World &copyObject);

		// destructor 
	~World ();

		// overloaded assignment operator
	World & operator = (World &rhs);

		// Functions
	void draw (sf::RenderWindow &theWindow);

private:
	vector<Room> mRooms;
	Hero mHero;
	frameTools mFrameCount;
};

#endif