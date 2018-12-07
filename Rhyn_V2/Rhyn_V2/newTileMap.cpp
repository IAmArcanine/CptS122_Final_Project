#include "newTileMap.h"

// default constructor
newTileMap::newTileMap ()
{
} // end default constructor

// initialized constructor
newTileMap::newTileMap (sf::VertexArray theVertices, sf::Texture theTileset)
{
	cout << "newTileMap default constructor" << endl;
	this->mVertices = theVertices;
	this->mTileset  = theTileset;
} // end newTileMap initialized constructor

// destructor
newTileMap::~newTileMap ()
{
	cout << "newTileMap destructor called" << endl;
} // end newTileMap destructor

	// functions

// load
bool newTileMap::load(const string & tileset, sf::Vector2u tileSize, const int * tiles, 
		           unsigned int width, unsigned int height)
{
	int theContinue = 0; 

	// load the tileset texture
	if (!mTileset.loadFromFile(tileset))
	{
		cout << "tile set failed" << endl;
		return false;
	}

	cout << "tile set succeeded" << endl;

	// resize the vertex array to fit the level size
	mVertices.setPrimitiveType(sf::Quads);
	mVertices.resize(width * height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < width; ++i)
	for (unsigned int j = 0; j < height; ++j)
	{
		// get the current tile number
		int tileNumber = tiles[i + j * width];

		// find its position in the tileset texture
		int tu = tileNumber % (mTileset.getSize().x / tileSize.x);
		int tv = tileNumber / (mTileset.getSize().x / tileSize.x);

		// get a pointer to the current tile's quad
		sf::Vertex* quad = &mVertices[(i + j * width) * 4];

		// define its 4 corners
		quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
		quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
		quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
		quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

		// define its 4 texture coordinates
		quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
		quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
		quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
		quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

	} // end for loop(s)

	return true;
} // end load function

/*
// draw
void newTileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	cout << "newTileMap draw" << endl;
	// apply the transform
	// states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &mTileset;

	// draw the vertex array
	target.draw(mVertices, states);
} // end draw function
*/

sf::VertexArray newTileMap::getVertices ()
{
	return mVertices;
} // end getVertices function

sf::Texture newTileMap::getTileSet ()
{
	return mTileset;
} // end getTileSet function