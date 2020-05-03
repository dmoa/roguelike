#include "../include/Tile.hpp"

Tile::Tile(){}

Tile::Tile(std::string name, std::string category, int tileID, int tileLength, int tilesetWidth, bool canWalkOver, bool canPickUp)
{
	m_name = name;
	m_category = category;

	int quadX = tileID % (tilesetWidth / tileLength);
    int quadY = floor(tileID * tileLength / tilesetWidth);
	m_quad = sf::IntRect(quadX * tileLength, quadY * tileLength, tileLength, tileLength);

	m_canWalkOver = canWalkOver;
	m_canPickUp = canPickUp;
}

std::string Tile::GetName()
{
	return m_name;
}

std::string Tile::GetCategory()
{
	return m_category;
}

sf::IntRect Tile::GetQuad()
{
	return m_quad;
}

bool Tile::GetCanWalkOver()
{
	return m_canWalkOver;
}

bool Tile::GetCanPickUp()
{
	return m_canPickUp;
}