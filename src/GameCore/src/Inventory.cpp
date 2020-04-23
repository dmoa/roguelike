#include "../include/Inventory.hpp"

Inventory::Inventory() {}

void Inventory::setTileset(sf::Texture* texture)
{
	m_tilesetTexture = texture;
}

void Inventory::Draw(sf::RenderTexture renderTexture) {}

void Inventory::addItem(sf::string name, sf::rect quad)
{
	// create sprite with texture m_tilesetTexture and set its bounds to the quad
}

void Inventory::removeItem(sf::string name, sf::rect quad)
{
}