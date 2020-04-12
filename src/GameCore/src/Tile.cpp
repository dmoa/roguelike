#include "../include/Tile.hpp"

Tile::Tile(std::string name, bool canWalkOver, bool canPickUp)
{
	m_name = name;
	m_canWalkOver = canWalkOver;
	m_canPickUp = canPickUp;
}

std::string Tile::getName()
{
	return m_name;
}

bool getCanWalkOver()
{
	return m_canWalkOver;
}

bool getCanPickUp()
{
	return m_canPickUp;
}