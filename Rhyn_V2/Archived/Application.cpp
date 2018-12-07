#include "Application.h"

// default constructor
Application::Application ()
{
	World            theWorld;
	sf::RenderWindow theWindow;

	this->mWorld  = theWorld;
	this->mWindow = theWindow;
} // end Application default constructor

// copy constructor
Application::Application (Application &copyObject)
{
	this->mWorld  = copyObject.mWorld;
	this->mWindow = copyObject.mWindow;
} // end Application copy constructor
	
// destructor
Application::~Application ()
{
	cout << "Application destructor called" << endl;
} // end Application destructor

// overloaded assignment operator
Application & Application::operator = (Application &rhs)
{
	this->mWorld  = rhs.mWorld;
	this->mWindow = rhs.mWindow;

	return *this;
} // end Application overloaded assignment operator

void Application::startGame ()
{
		// create a World object
	World theWorld;
	sf::Texture spriteSheet;

		// load sprite sheet
	spriteSheet.loadFromFile ("Hero.png");

		// create a window
	mWindow.create (sf::VideoMode (800, 600), "The Adventures of Rhyn" );

	while (mWindow.isOpen () )
	{
		sf::Event gameEvent;

		while (mWindow.pollEvent (gameEvent) )
		{
			if (gameEvent.type == sf::Event::KeyPressed)
			{
				if (gameEvent.key.code == sf::Keyboard::Q)
				{
					mWindow.close ();
				} // end close window if Q is pressed
			} // end if key pressed

			switch (gameEvent.type)
			{
			case sf::Event::Closed:
				mWindow.close ();
				break;
			} // end switch case
		} // end while pollEvent gameEvent loop

		mWindow.clear   ();
		theWorld.draw   (mWindow);
		mWindow.display ();
	} // end while window is open loop

} // end startGame function