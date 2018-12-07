#include "Background.h"
class object
{
public:
	object();

	void render();
	void checkCollision ();

private:
	sf::Texture texture;
	
	sf::Sprite sprite;
};