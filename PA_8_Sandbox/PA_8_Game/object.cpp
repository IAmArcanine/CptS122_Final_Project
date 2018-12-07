#include "Object.h"

Object::Object(int x1, int x2, int y1, int y2)
{
	mLocation.left = x1;
	mLocation.width = x2 - x1;
	mLocation.top = y2;
	mLocation.height = y2 - y1;
}

Object::Object()
{
	mLocation.height = 0;
	mLocation.left = 0;
	mLocation.top = 0;
	mLocation.width = 0;

} // end default constructor

	
		// initialized constructor 2
Object::Object(sf::IntRect &location)
{
	this->mLocation = location;
} // end 
	
	//sf::Sprite &getSprite(void);
	
		// getter

sf::IntRect Object::getLocation(void)
{
	return mLocation;
}
	
		// functions
