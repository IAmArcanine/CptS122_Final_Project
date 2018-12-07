#ifndef NEWTileMap_H
#define NEWTileMap_H

#include "Object.h"

class newTileMap // : public sf::Drawable, public sf::Transformable
{
public:
		// default constructor
	newTileMap ();

		// initialized constructor
	newTileMap (sf::VertexArray theVertices, sf::Texture theTileset);

		// destructor
	~newTileMap ();

		// getters
	sf::VertexArray getVertices ();
	sf::Texture     getTileSet ();

		// functions
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, 
		      unsigned int width, unsigned int height);

private:
	sf::VertexArray mVertices;
    sf::Texture     mTileset;
};

#endif