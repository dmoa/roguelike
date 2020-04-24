#pragma once

#include "Item.hpp"

class Inventory
{
public:
	Inventory();
	void setTileset(sf::Texture* texture);
	void Draw(sf::RenderTexture* renderTexture);
	void addItem(std::string name, sf::IntRect quad);
	void removeItem(std::string name);
private:
	sf::Texture* m_texture;
	std::vector<Item> m_items;
};