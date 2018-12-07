#include "Background.h"

class graphicsComponent
{
public:
	virtual ~graphicsComponent (){
	};
	virtual void update(sf::Event event) = 0;
private:
	//all things with a component will need a texture
	sf::Texture newTexture;
};

class actorGraphicsComponent : public graphicsComponent
{
public:
	//initialize new texture and sprite
	actorGraphicsComponent();
	void update(sf::Event event){
		switch (event.key.code)
		{
			//change the sprite based on sheet
		}
	}
private:
	sf::Sprite actorSprite;

};

class menuGraphicsComponent : public graphicsComponent
{
public:
	//initialize new texture and sprite
	menuGraphicsComponent();
	void update(sf::Event event){
		switch (event.key.code)
		{
			//trigger menu pop-up
			//set no-action trigger flag
			//trigger menu action
		}
	}
private:
	sf::Sprite menuSprite;

};