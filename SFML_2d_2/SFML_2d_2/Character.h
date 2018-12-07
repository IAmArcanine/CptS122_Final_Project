#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;

class character
{
	friend class obstacle;

public:
		// move functions:

	void move_left  (sf::Sprite *theSprite, sf::Texture *theTexture);
	void move_right (sf::Sprite *theSprite, sf::Texture *theTexture);
	void move_up    (sf::Sprite *theSprite, sf::Texture *theTexture);
	void move_down  (sf::Sprite *theSprite, sf::Texture *theTexture);
	
		// check position functions
	bool check_left  (sf::Sprite theSprite, obstacle theObstacle);
	bool check_right (sf::Sprite theSprite, obstacle theObstacle);
	bool check_up    (sf::Sprite theSprite, obstacle theObstacle);
	bool check_down  (sf::Sprite theSprite, obstacle theObstacle);

private:
};