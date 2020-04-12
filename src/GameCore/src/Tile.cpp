#include "../include/Tile.hpp"

Tile::Tile(){}

Tile::Tile(std::string name, std::string category, bool canWalkOver, bool canPickUp)
{
	m_name = name;
	m_category = category;
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

bool Tile::getCanWalkOver()
{
	return m_canWalkOver;
}

bool Tile::getCanPickUp()
{
	return m_canPickUp;
}