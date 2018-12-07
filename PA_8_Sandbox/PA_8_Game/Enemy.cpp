#include "Enemy.h"

Enemy::Enemy ()
{
}

Enemy::Enemy (Enemy &copyObject)
{
}

Enemy::~Enemy ()
{
}

Enemy & Enemy:: operator = (Enemy &rhs)
{
}

void Enemy::decideMovement (sf::IntRect &heroLocation)
{
	if (this->getLocation().left - heroLocation.left > this->getLocation().top - heroLocation.top)
	{

	}
}