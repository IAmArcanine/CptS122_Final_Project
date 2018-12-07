// #include "Character.h"
#include "character.h"
#include "obstacle.h"

// move left
void character::move_left(sf::Sprite *theSprite, sf::Texture *theTexture)
{
		// prevent the sprite from moving past the screen:
	if ((*theSprite).getPosition().x > 0)
	{
		(*theTexture).loadFromFile ("Character_Left.png");
		(*theSprite).move (-1, 0);
	} // end move only if we're not off the screen

} // end move_left

// move right
void character::move_right(sf::Sprite *theSprite, sf::Texture *theTexture)
{
		// prevent the sprite from moving past the screen:
	if ((*theSprite).getPosition().x < 750)
	{
		(*theTexture).loadFromFile ("Character_Right.png");
		(*theSprite).move (1, 0);
	}

} // end move_right

// move up
void character::move_up(sf::Sprite *theSprite, sf::Texture *theTexture)
{
		// prevent the sprite from moving past the screen:
	if ((*theSprite).getPosition().y > 0)
	{
		(*theTexture).loadFromFile ("Character_Up.png");
		(*theSprite).move (0, -1);
	}

} // end move_up

// move down
void character::move_down(sf::Sprite *theSprite, sf::Texture *theTexture)
{
		// prevent the sprite from moving past the screen:
	if ((*theSprite).getPosition().y < 540)
	{
		(*theTexture).loadFromFile ("Character_Down.png");
		(*theSprite).move (0, 1);
	}

} // end move_down

// check_left
bool character::check_left  (sf::Sprite theSprite, sf::Sprite theObstacle)
{
	bool valid = false;

	sf::FloatRect boundingBox = theSprite.getGlobalBounds();
	sf::FloatRect obstacleBox = theObstacle.getGlobalBounds ();
		
	/*
	cout << "boundingBox.left: " << boundingBox.left << endl;
	cout << "obstacleBox.left: " << obstacleBox.left << endl;
	cout << "obstacleBox.width: " << obstacleBox.width << endl << endl;
	*/

		// this will check all four sides of the boundaries of both the obstacle and the character -- works!
	if (((boundingBox.left - 1) <= obstacleBox.left + obstacleBox.width) && 
		(boundingBox.top <= (obstacleBox.top + obstacleBox.height)) 
		&& ((boundingBox.top + boundingBox.height) >= obstacleBox.top)
		&& ((boundingBox.left + boundingBox.width) >= (obstacleBox.left + obstacleBox.width)) )
	// if (boundingBox.intersects(obstacleBox)) // this only checks after we are already inside the obstacle
	{
		// do nothing, valid is already false
	} // end if collision detected
	else
	{
		valid = true;
	} // end else, no collision detected so set valid to true

	return valid;
} // end check_left

// check_right
bool character::check_right (sf::Sprite theSprite, sf::Sprite theObstacle)
{
	bool valid = false;

	sf::FloatRect boundingBox = theSprite.getGlobalBounds();
	sf::FloatRect obstacleBox = theObstacle.getGlobalBounds ();
		
			// this will check all four sides of the boundaries of both the obstacle and the character -- works!
	if (((boundingBox.left) <= obstacleBox.left) && 
		(boundingBox.top <= (obstacleBox.top + obstacleBox.height)) 
		&& ((boundingBox.top + boundingBox.height) >= obstacleBox.top)
		&& ((boundingBox.left + boundingBox.width) + 1 >= (obstacleBox.left)) )
	// if (boundingBox.intersects(obstacleBox))
	{
		// do nothing, valid is already false
	}
	else
	{
		valid = true;
	}

	return valid;
} // end check_right

// check_up
bool character::check_up (sf::Sprite theSprite, sf::Sprite theObstacle)
{
	bool valid = false;
	sf::FloatRect boundingBox = theSprite.getGlobalBounds();
	sf::FloatRect obstacleBox = theObstacle.getGlobalBounds ();
		
			// this will check all four sides of the boundaries of both the obstacle and the character -- works!
	if (((boundingBox.left) <= (obstacleBox.left + obstacleBox.width)) && 
		(((boundingBox.top) - 1) <= (obstacleBox.top + obstacleBox.height)) 
		&& ((boundingBox.top + boundingBox.height) >= (obstacleBox.top + obstacleBox.height))
		&& ((boundingBox.left + boundingBox.width) >= (obstacleBox.left)) )
	// if (boundingBox.intersects(obstacleBox))
	{
		// do nothing, valid is already false
	}
	else
	{
		valid = true;
	}

	return valid;
} // end check_up

// check_down
bool character::check_down (sf::Sprite theSprite, sf::Sprite theObstacle)
{
	bool valid = false;

	sf::FloatRect boundingBox = theSprite.getGlobalBounds();
	sf::FloatRect obstacleBox = theObstacle.getGlobalBounds ();
		
			// this will check all four sides of the boundaries of both the obstacle and the character -- works!
	if (((boundingBox.left) <= (obstacleBox.left + obstacleBox.width)) && 
		(((boundingBox.top)) <= (obstacleBox.top + obstacleBox.height)) 
		&& ((boundingBox.top + boundingBox.height) + 1 >= (obstacleBox.top))
		&& ((boundingBox.left + boundingBox.width) >= (obstacleBox.left)) )
	// if (boundingBox.intersects(obstacleBox))
	{
		// do nothing, valid is already false
	}
	else
	{
		valid = true;
	}

	return valid;
} // end check_down