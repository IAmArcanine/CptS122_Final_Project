#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

//a test from an idea from http://gameprogrammingpatterns.com/component.html
#include "Background.h"
#include "World.h"
#include "Application.h"

//really fascinating and it ties into polymorphism from class, so take a look
class inputComponent
{
	//so we can re-use for menu
	// virtual ~inputComponent (){	};
	virtual void update(sf::Event event) = 0;

};

class playerInputComponent : public inputComponent
{
public:
	~playerInputComponent ()
		{
			cout << "Does nothing" << endl;
	}

void update(sf::Event event)
  {
    switch (event.key.code)
    {
		case sf::Keyboard::A:
        //moves left
        break;

		case sf::Keyboard::D:
        //moves right
        break;

		case sf::Keyboard::S:
		//moves down
		break;

		case sf::Keyboard::W:
		//moves up
		break;
		//other player input like trigger menu or attck
    }
  }
};

class menuInputComponent : public inputComponent
{
	/*
	void update(sf::Event event)
	{
		switch(event.key.code)
		{
			//case statements when within menu
		}
	}
	*/
};

#endif