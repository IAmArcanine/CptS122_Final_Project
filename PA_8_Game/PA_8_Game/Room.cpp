#include "Room.h"

Room::Room(std::string filepath)
{
	std::ifstream openfile(filepath.c_str());
	
	sf::Texture tileTexture;
	sf::Sprite map;

	if (openfile.is_open())
	{
		std::string tileLocation;
		openfile >> tileLocation; //this gets the path to the tilemapFile.png
		tileTexture.loadFromFile(tileLocation);
		map.setTexture(tileTexture);
		while (!openfile.eof())
		{
			
		}

	}



}