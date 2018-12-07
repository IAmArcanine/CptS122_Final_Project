#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Room.h"
#include "Character.h"
class World 
{
	public:
		World();
		void draw(sf::RenderWindow &window);
	
	private:
		std::vector<Room> rooms;
	    
};


#endif