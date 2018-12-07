#include "Actor.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: default constructor
* Description: Default constructor for Actor class, sets everything to zero
* Precondition: Actor class must be instantiated
* Postcondition: an instance of Actor class will be created with its 
* private data members initialized to zero
*********************************************************************************/

Actor::Actor ()
{
	this -> mHealth   = 0;
	this -> mArmor    = 0;
	this -> mShield   = 0;
	this -> mAttack   = 0;
	this -> mMovement = 1;
	this -> mShield   = 1;
} // end default constructor
	
/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: copy constructor
* Description: copy constructor for Actor class
* Precondition: Actor class must be being copied
* Postcondition: a new instance of Actor class will be created with its 
* private data members set to the version of the Actor class that is being
* copied
*********************************************************************************/

Actor::Actor (Actor &copyObject)
{
	this -> mHealth = copyObject.mHealth;
	this -> mArmor  = copyObject.mArmor;
	this -> mShield = copyObject.mShield;
	this -> mAttack = copyObject.mAttack;
} // end copy constructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: destructor
* Description: Destructor for Actor class
* Precondition: Actor class must be going out of scope
* Postcondition: currently only prints a message to the screen
*********************************************************************************/

Actor::~Actor ()
{
	cout << "Actor destructor was called" << endl;
} // end destructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: overloaded assignment operator
* Description: Defines how to set private data members when an instantiation of 
* Actor class is being assigned to another instance of the Actor class
* Precondition: Actor class must be instantiated
* Postcondition: an instance of Actor class will contain the values of 
* another instantiation of the Actor class
*********************************************************************************/

Actor & Actor::operator = (Actor &rhs)
{
	this -> mHealth = rhs.mHealth;
	this -> mArmor  = rhs.mArmor;
	this -> mShield = rhs.mShield;
	this -> mAttack = rhs.mAttack;
} // end overloaded assignment operator

	// getters:

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: getHealth
* Description: Getter for Actor class private data member: mHealth
* Precondition: Actor class must be instantiated
* Postcondition: The value of the mHealth variable in the instance will be
* returned as a double
*********************************************************************************/

double Actor::getHealth ()
{
	return mHealth;
} // end getHealth function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: getArmor
* Description: Getter for Actor class private data member: mArmor
* Precondition: Actor class must be instantiated
* Postcondition: The value of the mArmor variable in the instance will be
* returned as a double
*********************************************************************************/

double Actor::getArmor  ()
{
	return mArmor;
} // end getArmor function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: getShield
* Description: Getter for Actor class private data member: mShield
* Precondition: Actor class must be instantiated
* Postcondition: The value of the mShield variable in the instance will be
* returned as a double
*********************************************************************************/

double Actor::getShield ()
{
	return mShield;
} // end getArmor function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: getAttack
* Description: Getter for Actor class private data member: Attack
* Precondition: Actor class must be instantiated
* Postcondition: The value of the Attack variable in the instance will be
* returned as a double
*********************************************************************************/

double Actor::getAttack ()
{
	return mAttack;
} // end getAttack function

	// setters:

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: setHealth
* Description: Setter for Actor class private data member: mHealth
* Precondition: Actor class must be instantiated
* Postcondition: The value of the mHealth variable in the instance will be
* set to the value that is passed in
*********************************************************************************/

void Actor::setHealth (double newHealth)
{
	this -> mHealth = newHealth;
} // end setHealth

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: setArmor
* Description: Setter for Actor class private data member: mArmor
* Precondition: Actor class must be instantiated
* Postcondition: The value of the mArmor variable in the instance will be
* set to the value that is passed in
*********************************************************************************/

void Actor::setArmor  (double newArmor)
{
	this -> mArmor = newArmor;
} // end setArmor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: setShield
* Description: Setter for Actor class private data member: mShield
* Precondition: Actor class must be instantiated
* Postcondition: The value of the mShield variable in the instance will be
* set to the value that is passed in
*********************************************************************************/

void Actor::setShield  (double newShield)
{
	this -> mShield = newShield;
} // end setArmor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: setAttack
* Description: Setter for Actor class private data member: mAttack
* Precondition: Actor class must be instantiated
* Postcondition: The value of the mAttack variable in the instance will be
* set to the value that is passed in
*********************************************************************************/

void Actor::setAttack (double newAttack)
{
	this -> mAttack = newAttack;
} // end setAttack

	// gameplay functions:



/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: evaluateAttack
* Description: Describes the actions to take when defending an attack from an opponent
* Precondition: Actor class must be instantiated, opponent class must be 
* instantiated
* amount of Actors armor and shield must be passed in as a pointer argument
* amount of damage an oppent can inflict must be passed in as a pointer argument
* Postcondition: The value of the mHealth variable for the opponent will be 
* set to the value that is determined by the opponents attack and the Actors
* Armor and whether or not we are defending ourselves
* ////
* Armor and Shield private members?
*********************************************************************************/

void Actor::evaluateAttack (double *theArmor, double *theShield, int defendFlag, 
								double *attack, double *health)
{
	if (defendFlag == 1)
	{
		*health = (*health - (*attack / *theArmor));
	} // end if defending
	else
	{
		*health = (*health - *attack);
	} // end we are not defending, full attack strength

} // end evaluateAttack