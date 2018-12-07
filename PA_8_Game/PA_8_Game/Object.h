#include "Background.h"

class Object
{
public:
	Object();
	Object(int x1, int x2, int y1, int y2);
	Object(sf::IntRect location);
	//sf::Sprite &getSprite(void);
	sf::IntRect &getLocation(void);
	void checkCollision ();
	

private:
	//sf::Texture texture; This is not needed. The texture will be part of the sprite
	sf::Sprite mSprite;
	//because textures are a part of the map, and walls along the side are a type of object
	sf::IntRect mLocation;
};
// will move to its own header if 
class renderObject:Object
{

};