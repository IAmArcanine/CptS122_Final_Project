#pragma once
#define _CRT_SECURE_NO_WARNINGS

// #include "Actor.h"
#include "Object.h"

typedef struct 
{
	int width;
	int height;
}SIZE_t;

enum Direction{DOWN, UP, LEFT, RIGHT, SWING};
//forward declare room

class Actor : public Object
{
	friend class Room;
public:

		// default constructor
	Actor ();

		// initialized constructor
	Actor (string filePath);
	
		// copy constructor
	Actor (Actor &copyObject);

		// destructor
	~Actor ();

		// overloaded assignment operator
	Actor &operator = (Actor &rhs);

		// getters:
	double getHealth   ();
	double getArmor    ();
	double getShield   ();
	double getAttack   ();
	double getMovement ();
	double getSpeed    ();
	//graphicsComponent *getVisual ();
// 	playerInputComponent *getP1 ();

		// setters:
	void setHealth   (double newHealth);
	void setArmor    (double newArmor);
	void setShield   (double newArmor);
	void setAttack   (double newAttack);
	void setMovement (double newMovement);
	void setSpeed    (double newSpeed);
	//void setVisual  (graphicsComponent *newVisual);
//	void setP1      (playerInputComponent *newP1);

		// gameplay functions:

		// evaluate damage
	void evaluateAttack (double *theArmor, double *theShield, int defendFlag, 
		double *attack, double *health);


protected:
	double mHealth;  // health
	double mArmor;   // ability to withstand attack (without defending)
	double mShield;  // ability to defend from an attack
	double mAttack;  // damage dealt to opponent
	//graphicsComponent *visual;
//	playerInputComponent *p1;
	double mMovement;
	double mSpeed;
	sf::Texture newTexture;
	sf::Sprite newSprite;
};


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

	// getters
/*
	sf::Vector2i getSource ()
	{
		return source;
	} // end getSource

	SIZE_t getSize ()
	{
		return size;
	} // end getSize
	*/
	bool getFlag ()
	{
		return flag;
	} // end getFlag

	// setters
	void setSourceX (Direction newDirection)
	{
		source.x = newDirection;
	} // end getSource
	void setSourceY (int newDirection)
	{
		source.y = newDirection;
	} // end getSource

	void setSizeW (int newH)
	{
		size.height = newH;
	} // end getSize

	void setSizeH (int newH)
	{
		size.height = newH;
	} // end getSize
	
	void setFlag (bool newFlag)
	{
		flag = newFlag;
	} // end getFlag

	// specific sword attack function
	void attackSword    (double theAttack, sf::Sprite theActor, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection);
		// specific fireball attack function
	void attackFireball (double theAttack, sf::Sprite theActor, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection);
	sf::Vector2i getSource();
	SIZE_t getSize();

private:
	sf::Vector2i source;
	SIZE_t size;
	bool flag;

};
