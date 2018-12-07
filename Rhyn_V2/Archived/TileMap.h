#ifndef TILEMAP_H
#define TILEMAP_H

#define _CRT_SECURE_NO_WARNINGS

#include "Object.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
		// default constructor
	TileMap ();

		// initialized constructor
	TileMap (sf::VertexArray theVertices, sf::Texture theTileset);

		// copy constructor
	TileMap (TileMap &copyObject);

		// destructor
	~TileMap ();

		// overloaded assignment operator
	TileMap & operator = (TileMap &rhs);

		// functions
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, 
		      unsigned int width, unsigned int height);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::VertexArray mVertices;
    sf::Texture     mTileset;
};

#endif