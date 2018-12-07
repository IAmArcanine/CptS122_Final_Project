#include "Character.h"

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: default constructor
* Description: Default constructor for Character class, sets everything to zero
* Precondition: Character class must be instantiated
* Postcondition: an instance of character class will be created with its 
* private data members initialized to zero
*********************************************************************************/

Character::Character ()
{
	this -> mHealth = 0;
	this -> mArmor  = 0;
	this -> mShield = 0;
	this -> mAttack = 0;
} // end default constructor
	
/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: copy constructor
* Description: copy constructor for Character class
* Precondition: Character class must be being copied
* Postcondition: a new instance of character class will be created with its 
* private data members set to the version of the character class that is being
* copied
*********************************************************************************/

Character::Character (Character &copyObject)
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
* Description: Destructor for Character class
* Precondition: Character class must be going out of scope
* Postcondition: currently only prints a message to the screen
*********************************************************************************/

Character::~Character ()
{
	cout << "Character destructor was called" << endl;
} // end destructor

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: overloaded assignment operator
* Description: Defines how to set private data members when an instantiation of 
* Character class is being assigned to another instance of the character class
* Precondition: Character class must be instantiated
* Postcondition: an instance of character class will contain the values of 
* another instantiation of the character class
*********************************************************************************/

Character & Character::operator = (Character &rhs)
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
* Description: Getter for Character class private data member: mHealth
* Precondition: Character class must be instantiated
* Postcondition: The value of the mHealth variable in the instance will be
* returned as a double
*********************************************************************************/

double Character::getHealth ()
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
* Description: Getter for Character class private data member: mArmor
* Precondition: Character class must be instantiated
* Postcondition: The value of the mArmor variable in the instance will be
* returned as a double
*********************************************************************************/

double Character::getArmor  ()
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
* Description: Getter for Character class private data member: mShield
* Precondition: Character class must be instantiated
* Postcondition: The value of the mShield variable in the instance will be
* returned as a double
*********************************************************************************/

double Character::getShield ()
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
* Description: Getter for Character class private data member: Attack
* Precondition: Character class must be instantiated
* Postcondition: The value of the Attack variable in the instance will be
* returned as a double
*********************************************************************************/

double Character::getAttack ()
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
* Description: Setter for Character class private data member: mHealth
* Precondition: Character class must be instantiated
* Postcondition: The value of the mHealth variable in the instance will be
* set to the value that is passed in
*********************************************************************************/

void Character::setHealth (double newHealth)
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
* Description: Setter for Character class private data member: mArmor
* Precondition: Character class must be instantiated
* Postcondition: The value of the mArmor variable in the instance will be
* set to the value that is passed in
*********************************************************************************/

void Character::setArmor  (double newArmor)
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
* Description: Setter for Character class private data member: mShield
* Precondition: Character class must be instantiated
* Postcondition: The value of the mShield variable in the instance will be
* set to the value that is passed in
*********************************************************************************/

void Character::setShield  (double newShield)
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
* Description: Setter for Character class private data member: mAttack
* Precondition: Character class must be instantiated
* Postcondition: The value of the mAttack variable in the instance will be
* set to the value that is passed in
*********************************************************************************/

void Character::setAttack (double newAttack)
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
* Function: attackSword
* Description: Describes the actions to take when initiating a sword attack on an opponent
* Precondition: Character class must be instantiated, opponent class must be 
* instantiated
* Postcondition: The value of the mHealth variable for the opponent will be 
* set to the value that is determined by the opponents mhealth and the strength
* of our mAttack
* ////
* This function will also initiate attack "animation"
*********************************************************************************/

void attackSword (double theAttack, sf::Sprite theCharacter, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection)
{
		// create boundary boxes around the character and the opponent:
	sf::FloatRect characterArea = theCharacter.getGlobalBounds();
	sf::FloatRect opponentArea  = theOpponent.getGlobalBounds ();

		// call the function for the attack animation
	// attackAnimation ();

		// if we are facing right:
	if (theDirection == 'R')
	{
		if (
		(((characterArea.left + characterArea.width) + 32) >= opponentArea.left)
		&& (((characterArea.left + characterArea.width) + 32) <= (opponentArea.left + opponentArea.width))
		&& ((characterArea.top) <= ((opponentArea.top + opponentArea.height) + opponentArea.width))
		&& ((characterArea.top + characterArea.height) >= (opponentArea.top + opponentArea.width))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing left:
	if (theDirection == 'L')
	{
		if (
		(((characterArea.left) - 32) <= (opponentArea.left + opponentArea.width))
		&& (((characterArea.left) - 32) >= (opponentArea.left))
		&& ((characterArea.top) <= ((opponentArea.top + opponentArea.height) + opponentArea.width))
		&& ((characterArea.top + characterArea.height) >= (opponentArea.top + opponentArea.width))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing up:
	if (theDirection == 'U')
	{
		if (
		(((characterArea.left + characterArea.width)) >= opponentArea.left)
		&& ((characterArea.left) <= (opponentArea.left + opponentArea.width))
		&& ((characterArea.top - 32) <= ((opponentArea.top + opponentArea.height)))
		&& ((characterArea.top - 32) >= (opponentArea.top))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing down:
	if (theDirection == 'D')
	{
		if (
		(((characterArea.left + characterArea.width)) >= opponentArea.left)
		&& ((characterArea.left) <= (opponentArea.left + opponentArea.width))
		&& ((characterArea.top + characterArea.height + 32) <= ((opponentArea.top + opponentArea.height)))
		&& ((characterArea.top + characterArea.height + 32) >= (opponentArea.top))
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
* Precondition: Character class must be instantiated, opponent class must be 
* instantiated
* Postcondition: The value of the mHealth variable for the opponent will be 
* set to the value that is determined by the opponents mhealth and the strength
* of our mAttack
* ////
* This function will also initiate attack "animation"
*********************************************************************************/

void attackFireball (double theAttack, sf::Sprite theCharacter, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection)
{
		// create boundary boxes around the character and the opponent:
	sf::FloatRect characterArea = theCharacter.getGlobalBounds();
	sf::FloatRect opponentArea  = theOpponent.getGlobalBounds ();

		// call the function for the attack animation
	// attackAnimation ();

		// if we are facing right:
	if (theDirection == 'R')
	{
		if (
		(((characterArea.left + characterArea.width) + 320) >= opponentArea.left)
		&& (((characterArea.left + characterArea.width) + 320) <= (opponentArea.left + opponentArea.width))
		&& ((characterArea.top) <= ((opponentArea.top + opponentArea.height) + opponentArea.width))
		&& ((characterArea.top + characterArea.height) >= (opponentArea.top + opponentArea.width))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing left:
	if (theDirection == 'L')
	{
		if (
		(((characterArea.left) - 320) <= (opponentArea.left + opponentArea.width))
		&& (((characterArea.left) - 320) >= (opponentArea.left))
		&& ((characterArea.top) <= ((opponentArea.top + opponentArea.height) + opponentArea.width))
		&& ((characterArea.top + characterArea.height) >= (opponentArea.top + opponentArea.width))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing up:
	if (theDirection == 'U')
	{
		if (
		(((characterArea.left + characterArea.width)) >= opponentArea.left)
		&& ((characterArea.left) <= (opponentArea.left + opponentArea.width))
		&& ((characterArea.top - 320) <= ((opponentArea.top + opponentArea.height)))
		&& ((characterArea.top - 320) >= (opponentArea.top))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

	// if we are facing down:
	if (theDirection == 'D')
	{
		if (
		(((characterArea.left + characterArea.width)) >= opponentArea.left)
		&& ((characterArea.left) <= (opponentArea.left + opponentArea.width))
		&& ((characterArea.top + characterArea.height + 320) <= ((opponentArea.top + opponentArea.height)))
		&& ((characterArea.top + characterArea.height + 320) >= (opponentArea.top))
		)
		{
		// opponent.getHealth = (opponent.getHealth - this -> mAttack); // adjust the opponents health accordingly
		} // end if attack is successful
	}

} // end attackFireball function

/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/29/2015
* Function: evaluateAttack
* Description: Describes the actions to take when defending an attack from an opponent
* Precondition: Character class must be instantiated, opponent class must be 
* instantiated
* amount of characters armor and shield must be passed in as a pointer argument
* amount of damage an oppent can inflict must be passed in as a pointer argument
* Postcondition: The value of the mHealth variable for the opponent will be 
* set to the value that is determined by the opponents attack and the characters
* Armor and whether or not we are defending ourselves
* ////
* Armor and Shield private members?
*********************************************************************************/

void Character::evaluateAttack (double *theArmor, double *theShield, int defendFlag, 
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