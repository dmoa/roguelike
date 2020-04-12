#pragma once

class Tile {
public:
	Tile(std::string name, bool canWalkOver, bool canPickUp);
	std::string getName();
	bool getCanWalkOver();
	bool getCanPickUp();
private:
	std::string m_name;
	bool m_canWalkOver;
	bool m_canPickUp;
};