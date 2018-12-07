#include "World.h"

// default constructor
World::World ()
{
	sf::Sprite theSprite;
	sf::Texture theTexture;

	Room aRoom ("../Resources/Tileset-1.png");
	mRooms.push_back(aRoom);

	this->mHero.setArmor    (0);
	this->mHero.setAttack   (0);
	this->mHero.setFlag     (false);
	this->mHero.setHealth   (0);
	this->mHero.setMovement	(0);
	this->mHero.setShield   (0);
	this->mHero.setSizeH    (0);
	this->mHero.setSizeW    (0);
	this->mHero.setSourceX  (0);
	this->mHero.setSourceY  (0);
	this->mHero.setSpeed    (0);
	this->mHero.setSprite   (theSprite);
	this->mHero.setTexture  (theTexture);

	this->mFrameCount.frameCounter = 0;
	this->mFrameCount.frameSpeed   = 1;
	this->mFrameCount.frameSwitch  = 0;
} // end World default constructor

// initialized constructor
World::World (string filePath)
{
	Room aroom ("../Resources/Tileset-1.png");
} // end World initialized  constructor

// copy constructor
World::World (World &copyObject)
{
	this->mRooms      = copyObject.mRooms;
	this->mHero       = copyObject.mHero;
	this->mFrameCount = copyObject.mFrameCount;
} // end World copy constructor

// destructor 
World::~World ()
{
	cout << "World Destructor called" << endl;
} // end World destructor

// overloaded assignment operator
World & World::operator = (World &rhs)
{
	this->mRooms      = rhs.mRooms;
	this->mHero       = rhs.mHero;
	this->mFrameCount = rhs.mFrameCount;
} // end World overloaded assignment operator

// Render a window
void World::draw (sf::RenderWindow &theWindow)
{
	Hero theHero;
	mFrameCount.frameCounter = 0;
	mFrameCount.frameSpeed   = 1;
	mFrameCount.frameSwitch  = 0;

	mRooms.front ().draw (theWindow, theHero, mFrameCount);
} // end draw function