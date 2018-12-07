#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include "Hero.h"
#include "TileMap.h"
using std::vector;
typedef struct frames
{
	float frameCounter;
	float switchFrame;
	float frameSpeed;
	sf::Clock clock;
} FrameTools;

class Object;
class Room
{
	friend class Hero;
	public:
		
		// initialized constructor
		Room(string filepath); //pass it a text file with the path to the tileset to use
									//and the skeletal array to draw on

		//what does the room have?
		void draw(sf::RenderWindow &window, Hero &theHero, FrameTools &frameCount);

	private:
		vector<Object> mapdata;//this is all the entities on the map.
		TileMap theMap; //this is the loaded tilemap
	    
};

