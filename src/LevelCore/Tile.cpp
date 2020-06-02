#include "Tile.hpp"

Tile::Tile(){}

Tile::Tile(std::string name, sf::Color color, bool canWalkOver)
{
	m_name = name;
	m_color = color;
	m_canWalkOver = canWalkOver;
}

std::string Tile::GetName() { return m_name; }
sf::Color Tile::GetColor() { return m_color; }
bool Tile::GetCanWalkOver() { return m_canWalkOver; }