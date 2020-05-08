#include "../include/Tile.hpp"

Tile::Tile(){}

Tile::Tile(std::string name, bool canWalkOver)
{
	m_name = name;
	m_canWalkOver = canWalkOver;
}

std::string Tile::GetName() { return m_name; }
bool Tile::GetCanWalkOver() { return m_canWalkOver; }