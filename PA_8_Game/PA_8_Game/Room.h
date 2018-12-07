#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "Object.h"
#include "TileMap.h"
#include <iostream>
#include <fstream>

using std::vector;
using std::cin;

class Room
{
	public:
		Room(std::string filepath); //pass it a text file with the path to the tileset to use
									//and the skeletal array to draw on

		//what does the room have?
		void draw(sf::RenderWindow &window);
	private:
		std::vector<Object> mapdata;//this is all the entities on the map.
		TileMap map; //this is the loaded tilemap
	    
};



#endif