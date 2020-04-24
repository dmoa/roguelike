#include "../include/Tile.hpp"

Tile::Tile(){}

Tile::Tile(std::string name, std::string category, int tileID, int tileLength, int mapTileLength, int tilesetWidth, bool canWalkOver, bool canPickUp)
{
	m_name = name;
	m_category = category;
	int quadX = tileID % mapTileLength;
    int quadY = floor(tileID * tileLength / tilesetWidth);
	m_quad = sf::IntRect(quadX * tileLength, quadY * tileLength, tileLength, tileLength);

	m_canWalkOver = canWalkOver;
	m_canPickUp = canPickUp;
}

std::string Tile::getName()
{
	return m_name;
}

std::string Tile::getCategory()
{
	return m_category;
}

sf::IntRect Tile::getQuad()
{
	return m_quad;
}

bool Tile::getCanWalkOver()
{
	return m_canWalkOver;
}

bool Tile::getCanPickUp()
{
	return m_canPickUp;
}