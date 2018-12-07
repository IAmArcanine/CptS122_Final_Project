#include "Background.h"
#include "TileMap.h"
#include "World.h"
class Application
{
public:
	static void startGame (void);
	static World &getWorld (void);
	static sf::RenderWindow &getWindow(void);

private:
	static World world;
	static sf::RenderWindow window;
};