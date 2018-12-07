#ifndef ROOM_H
#define ROOM_H

#define _CRT_SECURE_NO_WARNINGS

#include "TileMap.h"
#include "Hero.h"

typedef struct frames
{
  float frameCounter;
  float frameSwitch;
  float frameSpeed;
  sf::Clock mClock;
} frameTools;

class Room
{
public:
    // default constructor
  Room ();

    // initialized constructor 1
  Room (Object theMapData, TileMap theMap);

    // initialized constructor 2
  Room (string filePath);

    // copy constructor
  Room (Room &copyObject);

    // destructor
  ~Room ();

    // overloaded assignment operator
  Room & operator = (Room &rhs);

    // Functions
  void draw(sf::RenderWindow &window, Hero &theHero, frameTools &frameCount);

private:
  vector<Object> mapData; // vector array of Objects??
  TileMap mMap;
};

#endif
