#pragma once

class Tile
{
public:
	Tile();
	Tile(std::string name, sf::Color color, bool canWalkOver);
	std::string GetName();
	sf::Color GetColor();
	bool GetCanWalkOver();
private:
	std::string m_name;
	sf::Color m_color;
	bool m_canWalkOver;
};