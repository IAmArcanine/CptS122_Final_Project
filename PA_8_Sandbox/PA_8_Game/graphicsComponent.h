//#ifndef GRAPHICSCOMPONENT_H
//#define GRAPHICSCOMPONENT_H
//
//#include "Background.h"
//
//using std::string;
//
//class graphicsComponent
//{
//public:
//	virtual ~graphicsComponent (){
//	};
//	virtual void updateCharacter(sf::RenderWindow &window, sf::Vector2i source, SIZE_t &size) = 0;
//	sf::Sprite &getSprite(){
//		//cout << "graphics component getsprite" << endl;
//		return newSprite;
//	}
//protected:
//	//all things with a component will need a texture
//	sf::Texture newTexture;
//	sf::Sprite newSprite;
//};
//
//class actorGraphicsComponent : public graphicsComponent
//{
//public:
//	//initialize new texture and sprite
//	actorGraphicsComponent (string filePath)
//	{
//		newTexture.loadFromFile (filePath);
//		newSprite.setTexture (newTexture);
//		newSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
//		// flag = true;
//		// source.x = DOWN;
//		// source.y = 0;
//		// size.height = 32;
//		// size.width = 32;
//		flag = true;
//	} // end actorGraphicsComponent function
//
//	void updateCharacter(sf::RenderWindow &window, sf::Vector2i source, SIZE_t &size){
//		sf::Event event;
//
//		while(window.pollEvent(event))
//		{
//		switch (event.type)
//		{
//			case sf::Event::KeyPressed:
//				flag = false;
//				if(event.key.code == sf::Keyboard::Up)
//				{
//					source.x = UP;
//					size.width = 32;
//					// newSprite.move(0, -2);
//				}
//
//				if (event.key.code == sf::Keyboard::Down)
//				{
//					source.x = DOWN;
//					size.width = 32;
//					// newSprite.move(0, 2);
//
//				}
//
//				if (event.key.code == sf::Keyboard::Right)
//				{
//					source.x = RIGHT;
//					size.width = -32;
//					// newSprite.move(2, 0);
//
//				}
//
//				if (event.key.code == sf::Keyboard::Left)
//				{
//					source.x = LEFT;
//					size.width = 32;
//					// newSprite.move(-2, 0);
//
//				}
//
//				if (event.key.code == sf::Keyboard::F)
//				{
//					source.x = SWING;
//					size.width = -32;
//					//swingSword.play ();
//				}
//				break;
//				
//			case sf::Event::KeyReleased:
//			{
//				flag = true;
//			}
//			
//		}
//		if (!flag)
//		{
//			newSprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, size.width, 32));
//
//		}
//		else
//		{
//			newSprite.setTextureRect(sf::IntRect(0, 32, 32, 32));
//		}
//
//		newSprite.setScale(1.25,1.25);
//
//		} // end switch
//
//	} // end updateCharacter function
//
//private:
//
//};
//
////class menuGraphicsComponent : public graphicsComponent
////{
////public:
////	//initialize new texture and sprite
////	menuGraphicsComponent();
////	void updateCharacter(sf::RenderWindow &window, sf::Vector2i source, SIZE_t &size){
////		switch (event.key.code)
////		{
////			//trigger menu pop-up
////			//set no-action trigger flag
////			//trigger menu action
////		}
////	}
////private:
////	sf::Sprite menuSprite;
////
////};
//
//#endif