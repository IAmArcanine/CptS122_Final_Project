/*********************************************************************************
* Programmer: Marcus Blaisdell
* Student ID: 097868639
* Programmer: Matthew Farren
* Student ID: 11406152
* Programmer: Connor Cole
* Student ID: 
* Class: CptS 122, Spring 2015; Lab Section 3
* Programming Assignment: PA8
* Date: 04/28/2015
* Description: This program performs the following:
*
*
*
**********************************************************************************/

#include "Background.h"
#include "character.h"
#include "obstacleSet.h"

typedef struct 
{
	int width;
	int hight;
}SIZE_t;

int main (void)
{
	int globberPos = 0, globberDir = 0, globberCycle = 0;
	character hero;
	obstacleSet obstacles;
	

	enum Direction{DOWN, UP, LEFT, RIGHT, SWING};
	Direction facing = DOWN;
	float frameCounter = 0, switchFrame = 100, frameSpeed = 275;
	SIZE_t size = {32, 32};
	bool flag = true;
	// create a window:
	sf::Vector2i source(DOWN, 0);
	int counter = 0;
	sf::RenderWindow window (sf::VideoMode (800, 600), "Adventures of Rhyn");

	sf::SoundBuffer swordSound;
	swordSound.loadFromFile("../Resources/swingSword.wav");
	sf::Sound swing;
	swing.setBuffer (swordSound);

	sf::SoundBuffer collisionSound;
	swordSound.loadFromFile("../Resources/swingSword.wav");
	sf::Sound collide;
	collide.setBuffer (collisionSound);

	sf::Clock clock;
	sf::Texture characterTexture;
	characterTexture.loadFromFile ("../Resources/Hirro.png");

	sf::Texture BackgroundTexture;
	BackgroundTexture.loadFromFile("../Resources/GameMap.png");

	sf::Sprite characterSprite;
	characterSprite.setTexture (characterTexture);

		// Globber one, basic
	sf::Texture enemyTexture;
	enemyTexture.loadFromFile ("../Resources/GlobberSS.png");
	
	sf::Sprite globberSprite;
	globberSprite.setTexture (enemyTexture);

		// Globber two, follower
	sf::Texture enemyTextureAI;
	enemyTextureAI.loadFromFile ("../Resources/GlobberSS.png");
	
	sf::Sprite globberSpriteAI;
	globberSpriteAI.setTexture (enemyTextureAI);
	
	sf::Sprite background;
	background.setTexture (BackgroundTexture);

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
					facing = UP;
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					source.x = DOWN;
					size.width = 32;
					facing = DOWN;
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					source.x = RIGHT;
					size.width = -32;
					facing = RIGHT;

				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					source.x = LEFT;
					size.width = 32;
					facing = LEFT;
				}
				else if (event.key.code == sf::Keyboard::F)
				{
					switch (facing)
					{
						case DOWN:
							source.x = SWING;
							size.width = -32;
							switchFrame = 25;
						break;
						case UP:
							source.x = SWING+2;
							size.width = -32;
							switchFrame = 25;

						break;
						case RIGHT:
							source.x = SWING+1;
							size.width = -32;
							switchFrame = 25;
						break;
						case LEFT:
							source.x = SWING;
							size.width = 32;
							switchFrame = 25;

						break;
					}
					swing.play();

				}
			break;
			case sf::Event::KeyReleased:
				flag = true;
			break;
			}

		}

			// globber one movement:
		if (globberDir == 0 && globberSprite.getPosition ().x < 250)
		{
			globberSprite.move (0.5,0);
		}
		else if (globberSprite.getPosition ().x == 250 && globberDir == 0)
		{
			globberDir = 1;
		}
		else if (globberDir == 1 && globberSprite.getPosition ().x >0)
		{
			globberSprite.move (-0.5,0);
		}
		else if (globberSprite.getPosition ().x == 0 && globberDir == 1)
		{
			globberDir = 0;
		}

		if (((int) (globberSprite.getPosition ().x) % 2) == 0)
		{
			globberSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		}
		else
		{
			globberSprite.setTextureRect(sf::IntRect(0, 32, 32, 64));
		}

			// globber two movement:

			// only move every 100 cycles
		if (globberCycle < 100)
		{
			globberCycle++;
		}
		else
		{

		int globberX = 0, globberY = 0; // use absolute values to evaluate delta x and delta y

			// subtract character position from globber position, store value in globberX for eval
		globberX = (((globberSprite.getPosition ().x) - (characterSprite.getPosition ().x)) < 0);

			// subtract character position from globber position, store value in globberY for eval
		globberY = (((globberSprite.getPosition ().y) - (characterSprite.getPosition ().y)) < 0);

			// if delta X is negative, multiply by negative 1 to become positive
		if (globberX < 0)
		{
			globberX = globberX * (-1);
		} // end if globberX is negative, make positive

			// if delta Y is negative, multiply by negative 1 to become positive
		if (globberY < 0)
		{
			globberY = globberY * (-1);
		} // end if globberY is negative, make positive

			// if the difference in X's is greater than difference in Y's
			// move in the X direction towards the character
		if (globberX >= globberY)
		{
				// if globber position is greater than character, move left
			if (globberSpriteAI.getPosition ().x >= characterSprite.getPosition ().x)
			{
				globberSpriteAI.move (-1,0);
			} // end if we are to the players right
			else
			{
					// move right
				globberSpriteAI.move (1,0);
			} // end if we are to the players left

		} // end if delta X is greater than delta Y

		else // delta Y is greater than delta X
		{
				// if globber position is greater than character, move up
			if (globberSpriteAI.getPosition ().y >= characterSprite.getPosition ().y)
			{
					// move up
				globberSpriteAI.move (0,-1);
			} // end move up if we are below player
			else
			{
					// move down
				globberSpriteAI.move (0,1);
			} // end move down if we are above
		} // end if statement to control globber Y movement

			// simple modulus to change graphic
		if (((int) (globberSprite.getPosition ().x) % 2) == 0)
		{
			globberSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
		} // end if mod 2 == 0, load first graphic
		else
		{
			globberSprite.setTextureRect(sf::IntRect(0, 32, 32, 64));
		} // end if mod 2 != 0, load second graphic

			// simple modulus to change graphic
		if (((int) (globberSpriteAI.getPosition ().x) % 2) == 0)
		{
			globberSpriteAI.setTextureRect(sf::IntRect(0, 0, 32, 32));
		} // end if mod 2 == 0, load first graphic
		else
		{
			globberSpriteAI.setTextureRect(sf::IntRect(0, 32, 32, 64));
		} // end if mod 2 != 0, load second graphic

		globberCycle = 0;
		} // end only move every 100 cycles

		////cout << "Globber X: " << globberSprite.getPosition ().x;
		////cout << "Globber Y: " << globberSprite.getPosition ().y << endl << endl;
		////cout << "Rhyn X: " << characterSprite.getPosition ().x;
		////cout << "Rhyn Y: " << characterSprite.getPosition ().y << endl << endl;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			bool valid1 = false;
			valid1 = hero.check_up(characterSprite,obstacles.obstacles,3);
			if (valid1 == true)
			{
			characterSprite.move(0, -0.1);
			}
			else
			{
				collide.play();
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			bool valid1 = false;
			valid1 = hero.check_down(characterSprite,obstacles.obstacles,3);
			if (valid1 == true)
			{
				characterSprite.move(0, 0.1);
			}
			else
			{
				collide.play();
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bool valid1 = false;
			valid1 = hero.check_right(characterSprite,obstacles.obstacles,3);
			if (valid1 == true)
			{
				characterSprite.move(0.1, 0);
			}
			else
			{
				collide.play();
			}
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bool valid1 = false;
			valid1 = hero.check_left(characterSprite,obstacles.obstacles,3);
			if (valid1 == true)
			{
				characterSprite.move(-.1, 0);
			}
			else
			{
				collide.play();
			}
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

		
		sf::View mainBackground (sf::Vector2f(characterSprite.getPosition()), sf::Vector2f(16, 16));
		mainBackground.setSize(48, 48);
		
		if (!flag)
		{
			characterSprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, size.width, 32));

		}
		else
		{
			switch (facing)
			{
				case DOWN:
					characterSprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
				break;

				case UP:
					characterSprite.setTextureRect(sf::IntRect(32, 32, 32, 32));

				break;
				case LEFT:
					
					characterSprite.setTextureRect(sf::IntRect(64, 32, 32, 32));

				break;
				case RIGHT:
					characterSprite.setTextureRect(sf::IntRect(96, 32, -32, 32));
				break;
			}

		}

		//characterSprite.setPosition (48, 32);
		characterSprite.setScale(1.25,1.25);
		globberSprite.setScale(1.25, 1.25);
		mainBackground.setCenter(characterSprite.getPosition().x+16, characterSprite.getPosition().y+16);
		mainBackground.zoom(5);
		window.setView (mainBackground);
		// window.draw (map); // fix this, use static map
		window.draw(background);
		window.draw (globberSprite);
		window.draw (globberSpriteAI);
		window.draw (characterSprite);


		window.display ();
		window.clear (sf::Color::Green);
		switchFrame = 100;
		//size.width = 18;	
	} // end while window is open


	return 0;
}