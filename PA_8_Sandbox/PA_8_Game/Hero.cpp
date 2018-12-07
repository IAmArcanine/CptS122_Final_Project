#include "Hero.h"

// default constructor
Hero::Hero ()
{
	this -> setHealth (0);
	this -> setArmor (0);
	this -> setShield (0);
	this -> setAttack (0);
	this -> setMovement (1);
	this -> setSpeed (1);
	this -> newTexture.loadFromFile("../Resources/Hirro.png");
//	this -> setP1 (new playerInputComponent ());
	this -> mLocation.height = 0;
	this -> mLocation.left   = 0;
	this -> mLocation.top    = 0;
	this -> mLocation.width  = 0;
	size.height = 32;
	size.width = 32;
	source.x = DOWN;
	source.y = 0;
} // end default Hero constructor

	// copy constructors
Hero::Hero (Hero &copyObject)
{
	this -> setHealth (copyObject.getHealth ());
	this -> setArmor (copyObject.getArmor ());
	this -> setShield (copyObject.getShield ());
	this -> setAttack (copyObject.getAttack ());
	this -> setMovement (copyObject.getMovement ());
	this -> setSpeed (copyObject.getSpeed ());
//	this -> setVisual (copyObject.getVisual ());
//	this -> setP1 (copyObject.getP1 ());
	this -> mLocation.height = copyObject.mLocation.height;
	this -> mLocation.left   = copyObject.mLocation.left;
	this -> mLocation.top    = copyObject.mLocation.top;
	this -> mLocation.width  = copyObject.mLocation.width;
} // end Hero copy constructor

	// destructor
Hero::~Hero ()
{
	//cout << "Hero destructor was called" << endl;
} // end Hero destructor

	// overloaded assignment operator
Hero & Hero::operator = (Hero &rhs)
{
	this -> setHealth (rhs.getHealth ());
	this -> setArmor (rhs.getArmor ());
	this -> setShield (rhs.getShield ());
	this -> setAttack (rhs.getAttack ());
	this -> setMovement (rhs.getMovement ());
	this -> setSpeed (rhs.getSpeed ());
//	this -> setVisual (rhs.getVisual ());
//	this -> setP1 (rhs.getP1 ());
	this -> mLocation.height = rhs.mLocation.height;
	this -> mLocation.left   = rhs.mLocation.left;
	this -> mLocation.top    = rhs.mLocation.top;
	this -> mLocation.width  = rhs.mLocation.width;

	return *this;
}

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: attackSword
* Description: Describes the actions to take when initiating a sword attack on an opponent
* Precondition: Actor class must be instantiated, opponent class must be 
* instantiated
* Postcondition: The value of the mHealth variable for the opponent will be 
* set to the value that is determined by the opponents mhealth and the strength
* of our mAttack
* ////
* This function will also initiate attack "animation"
*********************************************************************************/

void attackSword (double theAttack, sf::Sprite theActor, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection)
{
		// define weapon range as 8 pixels ()
	int range = 8;

		// create boundary boxes around the Actor and the opponent:
	sf::FloatRect ActorArea = theActor.getGlobalBounds();
	sf::FloatRect opponentArea  = theOpponent.getGlobalBounds ();

		// call the function for the attack animation
	// attackAnimation ();

		// if we are facing right:
	if (theDirection == 'R')
	{
		if (
		(((ActorArea.left + ActorArea.width) + range) >= opponentArea.left)
		&& (((ActorArea.left + ActorArea.width) + range) <= (opponentArea.left + opponentArea.width))
		&& ((ActorArea.top) <= ((opponentArea.top + opponentArea.height) + opponentArea.width))
		&& ((ActorArea.top + ActorArea.height) >= (opponentArea.top + opponentArea.width))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing left:
	if (theDirection == 'L')
	{
		if (
		(((ActorArea.left) - range) <= (opponentArea.left + opponentArea.width))
		&& (((ActorArea.left) - range) >= (opponentArea.left))
		&& ((ActorArea.top) <= ((opponentArea.top + opponentArea.height) + opponentArea.width))
		&& ((ActorArea.top + ActorArea.height) >= (opponentArea.top + opponentArea.width))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing up:
	if (theDirection == 'U')
	{
		if (
		(((ActorArea.left + ActorArea.width)) >= opponentArea.left)
		&& ((ActorArea.left) <= (opponentArea.left + opponentArea.width))
		&& ((ActorArea.top - range) <= ((opponentArea.top + opponentArea.height)))
		&& ((ActorArea.top - range) >= (opponentArea.top))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing down:
	if (theDirection == 'D')
	{
		if (
		(((ActorArea.left + ActorArea.width)) >= opponentArea.left)
		&& ((ActorArea.left) <= (opponentArea.left + opponentArea.width))
		&& ((ActorArea.top + ActorArea.height + range) <= ((opponentArea.top + opponentArea.height)))
		&& ((ActorArea.top + ActorArea.height + range) >= (opponentArea.top))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

}

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: attackFireball
* Description: Describes the actions to take when initiating a Fireball attack on an opponent
* Precondition: Actor class must be instantiated, opponent class must be 
* instantiated
* Postcondition: The value of the mHealth variable for the opponent will be 
* set to the value that is determined by the opponents mhealth and the strength
* of our mAttack
* ////
* This function will also initiate attack "animation"
*********************************************************************************/

void attackFireball (double theAttack, sf::Sprite theActor, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection)
{
		// define range for attack
	int range = 320;

		// create boundary boxes around the Actor and the opponent:
	sf::FloatRect ActorArea = theActor.getGlobalBounds();
	sf::FloatRect opponentArea  = theOpponent.getGlobalBounds ();

		// call the function for the attack animation
	// attackAnimation ();

		// if we are facing right:
	if (theDirection == 'R')
	{
		if (
		(((ActorArea.left + ActorArea.width) + range) >= opponentArea.left)
		&& (((ActorArea.left + ActorArea.width) + range) <= (opponentArea.left + opponentArea.width))
		&& ((ActorArea.top) <= ((opponentArea.top + opponentArea.height) + opponentArea.width))
		&& ((ActorArea.top + ActorArea.height) >= (opponentArea.top + opponentArea.width))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing left:
	if (theDirection == 'L')
	{
		if (
		(((ActorArea.left) - range) <= (opponentArea.left + opponentArea.width))
		&& (((ActorArea.left) - range) >= (opponentArea.left))
		&& ((ActorArea.top) <= ((opponentArea.top + opponentArea.height) + opponentArea.width))
		&& ((ActorArea.top + ActorArea.height) >= (opponentArea.top + opponentArea.width))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing up:
	if (theDirection == 'U')
	{
		if (
		(((ActorArea.left + ActorArea.width)) >= opponentArea.left)
		&& ((ActorArea.left) <= (opponentArea.left + opponentArea.width))
		&& ((ActorArea.top - range) <= ((opponentArea.top + opponentArea.height)))
		&& ((ActorArea.top - range) >= (opponentArea.top))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing down:
	if (theDirection == 'D')
	{
		if (
		(((ActorArea.left + ActorArea.width)) >= opponentArea.left)
		&& ((ActorArea.left) <= (opponentArea.left + opponentArea.width))
		&& ((ActorArea.top + ActorArea.height + range) <= ((opponentArea.top + opponentArea.height)))
		&& ((ActorArea.top + ActorArea.height + range) >= (opponentArea.top))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

} // end attackFireball function

sf::Vector2i Hero::getSource()
{
	return source;
}
SIZE_t Hero::getSize()
{
	return size;
}