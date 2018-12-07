#include "Room.h"
#include <cctype>
#include "TileMap.h"


// initialized constructor
Room::Room(string filepath)
{
	//ifstream openfile(filepath.c_str());
	//sf::Texture tileTexture;
	//// sf::Sprite map;

	//if (openfile.is_open())
	//{
	//	std::string tileLocation;
	//	openfile >> tileLocation; //this gets the path to the tilemapFile.png
	//	tileTexture.loadFromFile(tileLocation);
		
	 // end if
	
	const int level[] = {19, 18,  6, 7,  3, 3, 11, 0,   1,  1,  1, 1, 17, 5, 5,  6, 
						 14, 15,  6, 3, 11, 3,  7, 4,   5,  5,  5, 5,  5, 5, 5,  6,
						 19, 18,  6, 7,  3, 0,  1, 17,  5, 12,  9, 9,  9, 9, 9, 10,
						  9,  9,  3, 3, 11, 4,  5,  5, 12, 10,  3, 11, 3, 0, 2,  7,
						19, 18,  6, 7,  3, 3, 11, 0,   1,  1,  1, 1, 17, 5, 5,  6, 
						 14, 15,  6, 3, 11, 3,  7, 4,   5,  5,  5, 5,  5, 5, 5,  6,
						 19, 18,  6, 7,  3, 0,  1, 17,  5, 12,  9, 9,  9, 9, 9, 10,
						  9,  9,  3, 3, 11, 4,  5,  5, 12, 10,  3, 11, 3, 0, 2,  7};
    
	/*THIS IS OUR BACKGROUND*/

	  theMap.load("../Resources/Tileset-1.png", sf::Vector2u(16, 16)/*pixel demensions of each tile*/,
				  level/*array to map from*/, 16/*number of columns in array*/, 8/*number of rows in array*/);
} // end initialized room constructor

// draw 
void Room::draw(sf::RenderWindow &window, Hero &theHero, FrameTools &frameCount)
{
	/*sf::Texture newTexture;
	newTexture.loadFromFile ("../Resources/Hirro.png");
	sf::Sprite newHero;*/
	// newHero.setTexture(newTexture);
	//newHero.setTexture(newTexture);
	//newHero.setTextureRect(sf::IntRect(0, 0, 32, 32));

	// theHero.getVisual()->updateCharacter(window);
	// theHero.getVisual()->updateCharacter(window,theHero.getSource(),theHero.getSize());
	//////////////////////////////
	sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				theHero.setFlag(false);
				if(event.key.code == sf::Keyboard::Up)
				{
					theHero.setSourceX(UP);
					theHero.setSizeW(32);
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					theHero.setSourceX(DOWN);
					theHero.setSizeW(32);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					theHero.setSourceX(RIGHT);
					theHero.setSizeW(-32);
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					theHero.setSourceX(LEFT);
					theHero.setSizeW(32);
				}
				else if (event.key.code == sf::Keyboard::F)
				{
					theHero.setSourceX(SWING);
					theHero.setSizeW(-32);
					frameCount.switchFrame = 25;
				}
			break;
			case sf::Event::KeyReleased:
				theHero.setFlag(true);
			break;
			}

		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			theHero.newSprite.move(0, -.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			theHero.newSprite.move(0, .1);
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			theHero.newSprite.move(.1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			theHero.newSprite.move(-.1, 0);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
		//	swing sword				
		}
		frameCount.frameCounter += frameCount.frameSpeed*frameCount.clock.restart().asSeconds();
		if (frameCount.frameCounter >= frameCount.switchFrame)
		{
			frameCount.frameCounter = 0;
			theHero.setSourceY(theHero.getSource().y + 1);
			if ((theHero.getSource().y * 32) >= theHero.newTexture.getSize().y)
				theHero.setSourceY(0);
		}

		
		cout << "CharacterTexture.getSize.y: " << theHero.newTexture.getSize().y <<endl;
		cout << "source.y: " << theHero.getSource().y << endl;
		sf::View mainBackground (sf::Vector2f(theHero.newSprite.getPosition()), sf::Vector2f(16, 16));
		mainBackground.setSize(48, 48);
		
		if (!theHero.getFlag())
		{
			theHero.newSprite.setTextureRect(sf::IntRect(theHero.getSource().x * 32, theHero.getSource().y * 32, theHero.getSize().width, 32));

		}
		else
		{
			theHero.newSprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
		}

	////////////////////////////////
	mainBackground.setCenter(theHero.newSprite.getPosition().x+16, theHero.newSprite.getPosition().y+16);
	mainBackground.zoom(5);
	window.setView (mainBackground);
	window.draw(theMap);
	//window.draw (newHero);
	// window.draw(theHero.getVisual()->getSprite());
	cout << "We are here" << endl;
	window.draw(theHero.newSprite);
	
	// window.display (); // this is in Application!
	
} // end draw function