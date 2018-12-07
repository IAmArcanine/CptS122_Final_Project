#include "Object.h"
#include "graphicsComponent.h"
#include "inputComponent.h"

class Character : public Object
{
public:

		// default constructor
	Character ();
	
		// copy constructor
	Character (Character &copyObject);

		// destructor
	~Character ();

		// overloaded assignment operator
	Character &operator = (Character &rhs);

		// getters:
	double getHealth ();
	double getArmor  ();
	double getShield ();
	double getAttack ();

		// setters:
	void setHealth (double newHealth);
	void setArmor  (double newArmor);
	void setShield (double newArmor);
	void setAttack (double newAttack);

		// gameplay functions:

	/*Matt:
		Is this the player, or a generic character class from which the player, enemy, and npc classes can be derived?
		I think we will merely want a swing sword move. The damage calculation will come into play when the sword collides with an enemy
		Also, defending will be just dodging??? Or do we want some form of shield?
	*/
	//maybe this should be a swordAttack()
	
		//** Added attackSword ** Marcus
	//and then we could have a fireballAttack()
		//** Added attackFireball ** Marcus

	//** removed generic attackOpponent, replaced by specific attack functions ** Marcus

	//and a sheildBlock()
		// **** need to ponder this one some more ****

		// specific sword attack function
	void attackSword    (double theAttack, sf::Sprite theCharacter, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection);
		// specific fireball attack function
	void attackFireball (double theAttack, sf::Sprite theCharacter, 
		sf::Sprite theOpponent, sf::Sprite theWeapon, char theDirection);

		// evaluate damage
	void evaluateAttack (double *theArmor, double *theShield, int defendFlag, 
		double *attack, double *health);


private:
	double mHealth;  // health
	double mArmor;   // ability to withstand attack (without defending)
	double mShield;  // ability to defend from an attack
	double mAttack;  // damage dealt to opponent
	characterGraphicsComponent visual;
	playerInputComponent p1;
	//we will also want a vector of equipment (probably a derived class from object??????)
	//vector<Equipment> mEquipment;
	//Also some form of inventory???
};