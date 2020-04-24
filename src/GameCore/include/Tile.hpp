#pragma once

class Tile {
public:
	Tile();
	Tile(std::string name, std::string category, int tileID, int tileLength, int mapTileLength, bool canWalkOver, bool canPickUp);
	std::string getName();
	std::string getCategory();
	sf::IntRect getQuad();
	bool getCanWalkOver();
	bool getCanPickUp();
private:
	std::string m_name;
	std::string m_category;
	sf::IntRect m_quad;
	bool m_canWalkOver;
	bool m_canPickUp;
};

// add category as well as name
// so I don't need to make it tree 1 tree 2 tree 3