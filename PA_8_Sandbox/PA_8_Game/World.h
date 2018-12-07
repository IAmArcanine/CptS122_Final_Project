#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Room.h"

class World 
{

	public:
			// default constructor
		World ();

			// initialized constructor
		World(string filePath);
			
			// functions
//	static Actor& getHero()
	Hero* getHero()
	{
		return &hero;
	}

	//draw
		void draw(sf::RenderWindow &window); // render a window
	
	private:
	vector<Room> mRooms;
	//static Actor *hero;
	Hero hero;
	FrameTools frameCount;
	
	
};
