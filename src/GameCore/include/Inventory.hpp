#pragma once

#include "Item.hpp"

class Inventory
{
public:
	Inventory();
	void setTexture(sf::Texture* texture);
	void Draw(sf::RenderTexture* renderTexture_noShader);
	void addItem(std::string name, sf::IntRect quad);
	void removeItem(std::string name);
private:
	sf::Texture* m_texture;
	std::vector<Item> m_items;
};