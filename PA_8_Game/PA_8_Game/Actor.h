#include "Object.h"
#include "graphicsComponent.h"
#include "inputComponent.h"

class Actor : public Object
{
public:

		// default constructor
	Actor ();
	
		// copy constructor
	Actor (Actor &copyObject);

		// destructor
	~Actor ();

		// overloaded assignment operator
	Actor &operator = (Actor &rhs);

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
		Is this the player, or a generic Actor class from which the player, enemy, and npc classes can be derived?
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

		//***** attackSword and attackFireball moved to Hero class *****

		// evaluate damage
	void evaluateAttack (double *theArmor, double *theShield, int defendFlag, 
		double *attack, double *health);


private:
	double mHealth;  // health
	double mArmor;   // ability to withstand attack (without defending)
	double mShield;  // ability to defend from an attack
	double mAttack;  // damage dealt to opponent
	actorGraphicsComponent visual;
	playerInputComponent p1;
	double mMovement;
	double mSpeed;
	//we will also want a vector of equipment (probably a derived class from object??????)
	//vector<Equipment> mEquipment;
	//Also some form of inventory???
};