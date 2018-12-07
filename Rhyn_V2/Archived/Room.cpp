#include "Room.h"

// default constructor
Room::Room ()
{
} // end Room default constructor

// initialized constructor 1
Room::Room (Object theMapData, TileMap theMap)
{
  // this->mapData = theMapData;
  this->mMap = theMap;
} // end Room initialized constructor 1

// initialized constructor 2
Room::Room (string filePath)
{
    // tile pixel dimensions are 16X16
    // this is an array of tiles to create the map,
    // the map as follows is defined as 16 columns by 4 rows
    // first 16 integers are the first row, second 16 second row, ...

  const int level[] = {19, 18,  6,  7,  3,  3, 11,  0,   1,  1,  1,  1, 17,  5,  5,  6,
             14, 15,  6,  3, 11,  3,  7,  4,   5,  5,  5,  5,  5,  5,  5,  6,
             19, 18,  6,  7,  3,  0,  1, 17,   5, 12,  9,  9,  9,  9,  9, 10,
              9,  9,  3,  3, 11,  4,  5,  5,  12, 10,  3, 11,  3,  0,  2,  7};

  /*THIS IS OUR BACKGROUND*/

  mMap.load("../Resources/Tileset-1.png", sf::Vector2u(16, 16), level, 16, 4);
} // end Room initialized constructor 2

// copy constructor
Room::Room (Room &copyObject)
{
  this->mapData = copyObject.mapData;
  this->mMap    = copyObject.mMap;
} // end Room copy constructor

// destructor
Room::~Room ()
{
  cout << "Room destructor called" << endl;
} // end Room destructor

// overloaded assignment operator
Room & Room::operator = (Room &rhs)
{
  this->mapData = rhs.mapData;
  this->mMap    = rhs.mMap;

  return *this;
} // end Room overloaded assignment operator

  // Functions
// draw
void Room::draw(sf::RenderWindow &window, Hero &theHero, frameTools &frameCount)
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
          frameCount.frameSwitch = 25;
        }
      break;
      case sf::Event::KeyReleased:
        theHero.setFlag(true);
      break;
      }

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      theHero.getSprite.move(0, -.1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      theHero.getSprite.move(0, .1);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      theHero.getSprite.move(.1, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      theHero.getSprite.move(-.1, 0);

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
    //	swing sword
    }
    frameCount.frameCounter += frameCount.frameSpeed*frameCount.mClock.restart().asSeconds();
    if (frameCount.frameCounter >= frameCount.frameSwitch)
    {
      frameCount.frameCounter = 0;
      theHero.setSourceY(theHero.getSource().y + 1);

      if ((theHero.getSource().y * 32) >= theHero.getTexture.getSize ().y)
      {
        theHero.setSourceY(0);
      }
    }


    cout << "CharacterTexture.getSize.y: " << theHero.getTexture.getSize().y <<endl;
    cout << "source.y: " << theHero.getSource().y << endl;

    sf::View mainBackground (sf::Vector2f(theHero.getSprite.getPosition()),
                           sf::Vector2f(16, 16));

    mainBackground.setSize(48, 48);

    if (!theHero.getFlag())
    {
      theHero.getSprite.setTextureRect (sf::IntRect(theHero.getSource().x * 32,
                                      theHero.getSource().y * 32,
                        theHero.getSize().width, 32));
    } // end if getFlag is false
    else
    {
      theHero.getSprite.setTextureRect (sf::IntRect (0, 32, 32, 32));
    } // end else, getFlag is true

  mainBackground.setCenter (theHero.getSprite.getPosition().x+16,
                          theHero.getSprite.getPosition().	y+16);
  mainBackground.zoom(5);
  window.setView (mainBackground);
  window.draw(mMap);
  window.draw(theHero.getSprite);

} // end draw function
