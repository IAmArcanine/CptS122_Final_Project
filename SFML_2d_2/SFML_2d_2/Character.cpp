// #include "Character.h"
#include "Obstacle.h"

// move left
void character::move_left(sf::Sprite *theSprite, sf::Texture *theTexture)
{
		// prevent the sprite from moving past the screen:
	if ((*theSprite).getPosition().x > 0)
	{
		(*theTexture).loadFromFile ("Character_Left.png");
		(*theSprite).move (-5, 0);
	} // end move only if we're not off the screen

} // end move_left

// move right
void character::move_right(sf::Sprite *theSprite, sf::Texture *theTexture)
{
		// prevent the sprite from moving past the screen:
	if ((*theSprite).getPosition().x < 750)
	{
		(*theTexture).loadFromFile ("Character_Right.png");
		(*theSprite).move (5, 0);
	}

} // end move_right

// move up
void character::move_up(sf::Sprite *theSprite, sf::Texture *theTexture)
{
		// prevent the sprite from moving past the screen:
	if ((*theSprite).getPosition().y > 0)
	{
		(*theTexture).loadFromFile ("Character_Up.png");
		(*theSprite).move (0, -5);
	}

} // end move_up

// move down
void character::move_down(sf::Sprite *theSprite, sf::Texture *theTexture)
{
		// prevent the sprite from moving past the screen:
	if ((*theSprite).getPosition().y < 540)
	{
		(*theTexture).loadFromFile ("Character_Down.png");
		(*theSprite).move (0, 5);
	}

} // end move_down

// check_left
bool character::check_left  (sf::Sprite theSprite, obstacle theObstacle)
{
	bool valid = false;

	if (((theSprite.getPosition ().x - 5) <= (theObstacle.getOriginX () + theObstacle.getSizeX () ))
		&& ((theSprite.getPosition ().x - 5) >= theObstacle.getOriginX ()) 
	    && (theSprite.getPosition ().y >= theObstacle.getOriginY () )
		&& (theSprite.getPosition ().y <= theObstacle.getOriginY () + theObstacle.getSizeY () ))
	{
		// do nothing, valid is already false
	}
	else
	{
		valid = true;
	}

	return valid;
} // end check_left

// check_right
bool character::check_right (sf::Sprite theSprite, obstacle theObstacle)
{
	bool valid = false;

	if (((theSprite.getPosition ().x - 5) <= (theObstacle.getOriginX () + theObstacle.getSizeX () ))
		&& ((theSprite.getPosition ().x - 5) >= theObstacle.getOriginX ()) 
	    && (theSprite.getPosition ().y >= theObstacle.getOriginY () )
		&& (theSprite.getPosition ().y <= theObstacle.getOriginY () + theObstacle.getSizeY () ))
	{
		// do nothing, valid is already false
	}
	else
	{
		valid = true;
	}

	return valid;
} // end check_right