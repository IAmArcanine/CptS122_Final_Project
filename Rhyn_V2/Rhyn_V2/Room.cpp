#include "Room.h"

	// Default constructor
Room::Room ()
{
	cout << "Room default constructor" << endl; // this is where we are setting our map!

	const int level[] = {19, 18,  6,  7,  3,  3, 11,  0,   1,  1,  1,  1, 17,  5,  5,  6,
                         14, 15,  6,  3, 11,  3,  7,  4,   5,  5,  5,  5,  5,  5,  5,  6,
                         19, 18,  6,  7,  3,  0,  1, 17,   5, 12,  9,  9,  9,  9,  9, 10,
                          9,  9,  3,  3, 11,  4,  5,  5,  12, 10,  3, 11,  3,  0,  2,  7};

	
	/*THIS IS OUR BACKGROUND*/

	mGameMap.load("../Resources/Tileset-1.png", sf::Vector2u(16, 16), level, 16, 4);
} // end default constructor

// initialized constructor
Room::Room (string filePath)
{
	cout << "Room initialized constructor" << endl; // this isn't getting called
	
    // tile pixel dimensions are 16X16
    // this is an array of tiles to create the map,
    // the map as follows is defined as 16 columns by 4 rows
    // first 16 integers are the first row, second 16 second row, ...

  const int level[] = {19, 18,  6,  7,  3,  3, 11,  0,   1,  1,  1,  1, 17,  5,  5,  6,
                       14, 15,  6,  3, 11,  3,  7,  4,   5,  5,  5,  5,  5,  5,  5,  6,
                       19, 18,  6,  7,  3,  0,  1, 17,   5, 12,  9,  9,  9,  9,  9, 10,
                        9,  9,  3,  3, 11,  4,  5,  5,  12, 10,  3, 11,  3,  0,  2,  7};

  /*THIS IS OUR BACKGROUND*/

  mGameMap.load("../Resources/Tileset-1.png", sf::Vector2u(16, 16), level, 16, 4);
} // end Room initialized constructor 2

	// had to instantiate these outside of the draw function
	// otherwise, they kept resetting the sprite position to (0, 0)
sf::Texture testTexture;
sf::Sprite testSprite;
	
Actor theActor;

// draw function
void Room::draw(sf::RenderWindow &theWindow, Hero &theHero, frameTools &frameCount)
{
	testTexture.loadFromFile ("../Resources/Hero.png");
	testSprite.setTexture (testTexture);
	// theActor.mTexture.loadFromFile ("../Resources/Hero.png");
	// theActor.mSprite.setTextureRect (sf::IntRect (0, 32, 32, 32) );

	sf::Event event;

    while (theWindow.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::Closed:
        theWindow.close();
        break;
      case sf::Event::KeyPressed:
        theHero.setFlag(false);
		if (event.key.code == sf::Keyboard::Q)
		{
			theWindow.close ();
		} // quit if Q is pressed
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
          frameCount.frameSwitch = 25;
        }
      break;
      case sf::Event::KeyReleased:
        theHero.setFlag(true);
      break;
      }

    }
	
	if (sf::Keyboard::isKeyPressed (sf::Keyboard::Up) )
    {
      // theHero.getSprite ().move(0, -.1);
	  testSprite.move (0, -0.1);
	  cout << "Up" << endl;
    } // end if key pressed is up arrow

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      // theHero.getSprite ().move(0, .1);
	  testSprite.move(0, 0.1);
	  cout << "Down" << endl;
    } // end if key pressed is down arrow

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      // theHero.getSprite ().move(.1, 0);
	  testSprite.move (0.1, 0);
	  cout << "Right" << endl;
    } // end if key pressed is right arrow
	/////
	else if (sf::Keyboard::isKeyPressed (sf::Keyboard::Right) &&
		     sf::Keyboard::isKeyPressed (sf::Keyboard::Up) )
	{
		testSprite.move (.1, -.1);
	}
	/////

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      // theHero.getSprite ().move(-.1, 0);
	  testSprite.move (-0.1, 0);
	  cout << "Left" << endl;
    } // end if key pressed is left arrow

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
    //	swing sword ??
    } // end else if keypressed is F

    frameCount.frameCounter += frameCount.frameSpeed*frameCount.frameClock.restart().asSeconds();

    if (frameCount.frameCounter >= frameCount.frameSwitch)
    {
      frameCount.frameCounter = 0;
      theHero.setSourceY(theHero.getSource().y + 1);

      if ((theHero.getSource ().y * 32) >= theHero.getTexture ().getSize ().y )
      {
        theHero.setSourceY(0);
      } // end if theHero source y*32 >= theHero y-size
    } // end if frameCounter >= frameSwitch

	cout << "Room::draw" << endl;
	
	sf::View mainBackground (sf::Vector2f (theHero.getSprite ().getPosition ().x, 
		                     theHero.getSprite ().getPosition ().y ),
                             sf::Vector2f (16, 16) );
	cout << "X: " << theHero.getSprite ().getPosition ().x
		 << "Y: " << theHero.getSprite ().getPosition ().y << endl;
	mainBackground.setSize (48, 48);
	mainBackground.setCenter (0, 0);
	mainBackground.zoom (5);
	///////
	
	if (!theHero.getFlag () )
    {
		cout << "getFlag = false" << endl;

//       theHero.getSprite ().setTextureRect (sf::IntRect (theHero.getSource ().x * 32,
//                                           theHero.getSource ().y * 32,
//                                           theHero.getSize ().width, 32) );
										   // not working ??
		// this works but prefer above method
		// first, use temp sprite, set its texture to desired
		// second, load theHero sprite from testSprite
		testSprite.setTextureRect (sf::IntRect (theHero.getSource ().x * 32,
									theHero.getSource ().y * 32,
									theHero.getSize ().width, 32) );
		theHero.setSprite (testSprite);
    } // end if getFlag is false
	else
    {
		cout << "getFlag = true" << endl;
		// theHero.getSprite ().setTextureRect (sf::IntRect (0, 32, 32, 32) );
		testSprite.setTextureRect (sf::IntRect (0, 32, 32, 32) );
		theHero.setSprite (testSprite);
    } // end else, getFlag is true
	//////////

	
		// load default image to testSprite then use to set theHero, this works
	// testSprite.setTextureRect (sf::IntRect (32, 32, 32, 32) ); // this works
	// theHero.setSprite (testSprite); // set theHero.mSprite with testSprite

	theWindow.setView (mainBackground);
	mGameMap.setPosition (-125, -10);
	theWindow.draw(mGameMap);

	theWindow.draw (theHero.getSprite () );
	// theWindow.draw (testSprite);

} // end draw function