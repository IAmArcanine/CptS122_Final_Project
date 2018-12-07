#include "Actor.h"

class Enemy:public Actor
{
public:
	// default constructor
	Enemy ();

		// copy constructor
	Enemy (Enemy &copyObject);

		// destructor
	~Enemy ();

		// overloaded assignment operator
	Enemy & operator = (Enemy &rhs);

	// specific sword attack function

	void decideMovement (sf::IntRect &heroLocation);
private:
	bool damageCollision;
	
};