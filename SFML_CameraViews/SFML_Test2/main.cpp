#include "Background.h"
#include "TileMap.h"
#include <stack>>

typedef struct 
{
	int width;
	int hight;
}SIZE_t;


int main (void)
{


	
	enum Direction{DOWN, UP, LEFT, RIGHT, SWING};
	float frameCounter = 0, switchFrame = 100, frameSpeed = 275;
	SIZE_t size = {32, 32};
	bool flag = true;
	// create a window:
	sf::Vector2i source(DOWN, 0);
	int counter = 0;
	sf::RenderWindow window (sf::VideoMode (800, 600), "Background test");
	//window.setFramerateLimit(60);
	//***********************************************************************************
	const int level[] = {19, 18,  6, 7,  3, 3, 11, 0,   1,  1,  1, 1, 17, 5, 5,  6, 
						 14, 15,  6, 3, 11, 3,  7, 4,   5,  5,  5, 5,  5, 5, 5,  6,
						 19, 18,  6, 7,  3, 0,  1, 17,  5, 12,  9, 9,  9, 9, 9, 10,
						  9,  9,  3, 3, 11, 4,  5,  5, 12, 10,  3, 11, 3, 0, 2,  7};
    
	/*THIS IS OUR BACKGROUND*/
	TileMap map; // object of TileMap class
	if (!map.load("../Resources/Tileset-1.png", sf::Vector2u(16, 16)/*pixel demensions of each tile*/,
				  level/*array to map from*/, 16/*number of columns in array*/, 4/*number of rows in array*/))
	{
		return -1;
	}
	//*********************************************************************************8


	sf::Clock clock;
	sf::Texture characterTexture;
	characterTexture.loadFromFile ("../Resources/Character.png");

	

	sf::Sprite characterSprite;
	characterSprite.setTexture (characterTexture);
	//characterSprite.setTextureRect(sf::IntRect(0,0, 18, 26));
	//cout << characterSprite.getTextureRect ().top;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				flag = false;
				if(event.key.code == sf::Keyboard::Up)
				{
					source.x = UP;
					size.width = 32;
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					source.x = DOWN;
					size.width = 32;
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					source.x = RIGHT;
					size.width = -32;
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					source.x = LEFT;
					size.width = 32;
				}
				else if (event.key.code == sf::Keyboard::F)
				{
					source.x = SWING;
					size.width = -32;
					switchFrame = 25;
				}
			break;
			case sf::Event::KeyReleased:
				flag = true;
			break;
			}

		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			characterSprite.move(0, -.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			characterSprite.move(0, .1);
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			characterSprite.move(.1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			characterSprite.move(-.1, 0);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
		//	swing sword				
		}
		frameCounter += frameSpeed*clock.restart().asSeconds();
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			source.y++;
			if ((source.y * 32) >= characterTexture.getSize().y)
				source.y = 0;
		}

		
		cout << "CharacterTexture.getSize.y: " << characterTexture.getSize().y <<endl;
		cout << "source.y: " << source.y << endl;
		sf::View mainBackground (sf::Vector2f(characterSprite.getPosition()), sf::Vector2f(16, 16));
		mainBackground.setSize(48, 48);
		
		if (!flag)
		{
			characterSprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, size.width, 32));

		}
		else
		{
			characterSprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
		}

		//characterSprite.setPosition (48, 32);
		characterSprite.setScale(1.25,1.25);
		mainBackground.setCenter(characterSprite.getPosition().x+16, characterSprite.getPosition().y+16);
		mainBackground.zoom(5);
		window.setView (mainBackground);
		window.draw (map);
		window.draw (characterSprite);

		window.display ();
		window.clear (sf::Color::Green);
		switchFrame = 100;
		//size.width = 18;	
	} // end while window is open

	return 0;
}	

