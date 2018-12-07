#include "obstacle.h"

class obstacleSet
{
public:
	obstacleSet()
	{
		obstacles = new obstacle[3];
		obstacles[0].collisionZone.height = 800;
		obstacles[0].collisionZone.left = -1;
		obstacles[0].collisionZone.width = 1;
		obstacles[0].collisionZone.top = 0;

		
		obstacles[1].collisionZone.height = 800;
		obstacles[1].collisionZone.left = -1;
		obstacles[1].collisionZone.width = 1;
		obstacles[1].collisionZone.top = 0;

		
		obstacles[2].collisionZone.height = 800;
		obstacles[2].collisionZone.left = -1;
		obstacles[2].collisionZone.width = 1;
		obstacles[2].collisionZone.top = 0;

	};
	~obstacleSet()
	{
		delete obstacles;
	}
	obstacle* obstacles;
};