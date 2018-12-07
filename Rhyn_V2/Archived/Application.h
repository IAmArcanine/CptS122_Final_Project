#ifndef APPLICATION_H
#define APPLICATION_H

#define _CRT_SECURE_NO_WARNINGS

#include "Hero.h"
#include "World.h"


class Application
{
public:
		// default constructor
	Application ();

		// copy constructor
	Application (Application &copyObject);
	
		// destructor
	~Application ();

		// overloaded assignment operator
	Application & operator = (Application &rhs);

		// Functions
	void startGame ();

private:
	World mWorld;
	sf::RenderWindow mWindow;	
};

#endif