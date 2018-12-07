#include "World.h"

// default constructor
World::World ()
{
	cout << "World default constructor called" << endl;
	
	Room aroom ("../Resources/Tileset-1.png");
	mRooms.push_back(aroom);

	frameCount.frameCounter = 0;
	frameCount.switchFrame = 100;
	frameCount.frameSpeed = 275;

} // end default constructor

// Initialized constructor
World::World (string filePath)
{
	cout << "World initialized constructor called" << endl;

	Room aroom ("../Resources/Tileset-1.png");
	mRooms.push_back(aroom);
	

} // end initialized constructor

// RenderWindow, pass window by reference
void World::draw(sf::RenderWindow &window)
{
	Hero Hirro;

	mRooms.front ().draw (window, Hirro, frameCount);
} // end draw function