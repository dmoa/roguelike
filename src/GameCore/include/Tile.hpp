#pragma once

class Tile {
public:
	Tile();
	Tile(std::string name, std::string category, bool canWalkOver, bool canPickUp);
	std::string getName();
	std::string getCategory();
	bool getCanWalkOver();
	bool getCanPickUp();
private:
	std::string m_name;
	std::string m_category;
	bool m_canWalkOver;
	bool m_canPickUp;
};

// add category as well as name
// so I don't need to make it tree 1 tree 2 tree 3