#pragma once

class Tile
{
public:
	Tile();
	Tile(std::string name, bool canWalkOver);
	std::string GetName();
	bool GetCanWalkOver();
private:
	std::string m_name;
	bool m_canWalkOver;
};