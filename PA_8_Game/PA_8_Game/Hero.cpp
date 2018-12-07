#include "Hero.h"

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
		// define weopon range as 8 pixels ()
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