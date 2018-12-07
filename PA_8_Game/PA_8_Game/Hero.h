#ifndef HERO_H
#define HERO_H

#include "Actor.h"

class Hero : public Actor
{
public:
		// default constructor
	Hero ();

		// copy constructor
	Hero (Hero &copyObject);

		// destructor
	~Hero ();

		// overloaded assignment operator
	Hero & operator = (Hero &rhs);

	// specific sword attack function
	void attackSword    (double theAttack, sf::Sprite theActor, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection);
		// specific fireball attack function
	void attackFireball (double theAttack, sf::Sprite theActor, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection);

private:

};

#endif