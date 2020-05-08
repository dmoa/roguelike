#pragma once

#include "Item.hpp"

class Inventory
{
public:
	Inventory();
	void SetTexture(sf::Texture* texture);
	void Draw(sf::RenderTexture* renderTexture_noShader);
	void AddItem(std::string name, sf::IntRect quad);
	void RemoveItem(std::string name);
private:
	sf::Texture* m_texture;
	std::vector<Item> m_items;
};