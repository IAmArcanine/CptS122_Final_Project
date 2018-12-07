#include "Object.h"

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
	double      mHealth;  // health
	double      mArmor;   // ability to withstand attack (without defending)
	double      mShield;  // ability to defend from an attack
	double      mAttack;  // damage dealt to opponent
	double      mMovement;
	double      mSpeed;
	sf::Texture newTexture;
	sf::Sprite  newSprite;
	// graphicsComponent *visual;
	// playerInputComponent *p1;
};