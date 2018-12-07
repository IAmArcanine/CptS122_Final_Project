#include "character.h"
#include "obstacle.h"

int main ()
{
		// create an instance of the character class:
	character theCharacter;
		// create two instances of the obstacle class:
	obstacle horizontalObstacle (200, 200, 60, 20);
	obstacle verticalObstacle (400, 400, 25, 45);
	bool valid = false;


		// create the window:
	sf::RenderWindow window (sf::VideoMode (800, 600), "My Window");

		// create the Sprite(s):
	sf::Texture texture; // create a Texture called texture (don't do that again, too confusing!)
	texture.loadFromFile ("Character_Right.png"); // default character image

	sf::Sprite characterSprite; // create a Sprite called characterSprite
	characterSprite.setTexture (texture);

		// experiment with sound
	sf::SoundBuffer collisionSound;
	collisionSound.loadFromFile("collide.wav");
	sf::Sound collide;
	collide.setBuffer (collisionSound);

		// create a vertical obstacle:
	sf::Texture obstacleVert;
	obstacleVert.loadFromFile ("VerticalObstacle.png");

	sf::Sprite obstacleVertSprite;
	obstacleVertSprite.setTexture (obstacleVert);

		// create a horizontal obstacle:
	sf::Texture obstacleHori;
	obstacleHori.loadFromFile ("HorizontalObstacle.png");

	sf::Sprite obstacleHoriSprite;
	obstacleHoriSprite.setTexture (obstacleHori);


		// run the program while the window is open

	while (window.isOpen())
	{
		//
		sf::Event event; // stop naming things with the type!

			// poll the system every cycle and use that info:

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
					// close window
				if (event.key.code == sf::Keyboard::Q)
				{
					window.close();
				} // end close window
			} // end close if Q is pressed

			if (event.type == sf::Event::Closed)
			{
				window.close();
			} // end if closed, close window

		} // end while pollEvent is true

		////
			// check if a key is pressed and perform appropriate action:

			if (event.type == sf::Event::KeyPressed)
			{

					// move left
				if (event.key.code == sf::Keyboard::Left)	
				{
					bool valid1 = false, valid2 = false;

					valid1 = theCharacter.check_left (characterSprite, obstacleHoriSprite);
					valid2 = theCharacter.check_left (characterSprite, obstacleVertSprite);

					if (valid1 == true && valid2 == true)
					{
						theCharacter.move_left (&characterSprite, &texture);
					} // end move if able
					else
					{
						collide.play();
						// cout << "I did not move" << endl;
						// theCharacter.move_right (&characterSprite, &texture);
					}
				} // end move left

					// move right
				if (event.key.code == sf::Keyboard::Right)	
				{
					bool valid1 = false, valid2 = false;
					valid1 = theCharacter.check_right (characterSprite, obstacleHoriSprite);
					valid2 = theCharacter.check_right (characterSprite, obstacleVertSprite);
					if (valid1 == true && valid2 == true)
					{
						theCharacter.move_right (&characterSprite, &texture);
					} // end move if able
					else 
					{
						collide.play();
						// cout << "I did not move" << endl;
						// theCharacter.move_left (&characterSprite, &texture);
					} // if invalid, move back to where we were

				} // end if Right

					// move up
				if (event.key.code == sf::Keyboard::Up)	
				{
					bool valid1 = false, valid2 = false;
					valid1 = theCharacter.check_up (characterSprite, obstacleHoriSprite);
					valid2 = theCharacter.check_up (characterSprite, obstacleVertSprite);
					if (valid1 == true && valid2 == true)
					{
						theCharacter.move_up (&characterSprite, &texture);
					} // end move if able
					else 
					{
						collide.play();
						// cout << "I did not move" << endl;
						// theCharacter.move_down (&characterSprite, &texture);
					} // if invalid, move back to where we were
					
				} // end if Up

					// move down
				if (event.key.code == sf::Keyboard::Down)	
				{
					bool valid1 = false, valid2 = false;
					valid1 = theCharacter.check_down (characterSprite, obstacleHoriSprite);
					valid2 = theCharacter.check_down (characterSprite, obstacleVertSprite);
					if (valid1 == true && valid2 == true)
					{
						theCharacter.move_down (&characterSprite, &texture);
					} // end move if able
					else 
					{
						collide.play();
						// cout << "I did not move" << endl;
						// theCharacter.move_up (&characterSprite, &texture);
					} // if invalid, move back to where we were
					
				} // end if Down

			} // end if keypressed
		////
			// draw the background:

		window.clear (sf::Color::Green);

			// put stuff:

			// obstacles (move these to classes)
		obstacleVertSprite.setPosition (sf::Vector2f(400,400));
		obstacleHoriSprite.setPosition (sf::Vector2f(200,200));

			// draw stuff

		window.draw (characterSprite);
		window.draw (obstacleVertSprite);
		window.draw (obstacleHoriSprite);

			// the key to it all:

		window.display ();

	} // end while

	return 0;
}