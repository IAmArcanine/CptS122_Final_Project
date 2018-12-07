#include "Object.h"
//knockback collision
class Weapon : public Object
{
public:
		// default constructor
	Weapon ();

		// copy constructor
	Weapon (Weapon &copyObject);

		// destructor
	~Weapon ();

		// overloaded assignment operator
	Weapon & operator = (Weapon &rhs);

private:
	double mRange;
	double mDamage;
};