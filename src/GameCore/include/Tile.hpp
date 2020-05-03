#pragma once

class Tile {
public:
	Tile();
	Tile(std::string name, std::string category, int tileID, int tileLength, int tilesetWidth, bool canWalkOver, bool canPickUp);
	std::string GetName();
	std::string GetCategory();
	sf::IntRect GetQuad();
	bool GetCanWalkOver();
	bool GetCanPickUp();
private:
	std::string m_name;
	std::string m_category;
	sf::IntRect m_quad;
	bool m_canWalkOver;
	bool m_canPickUp;
};