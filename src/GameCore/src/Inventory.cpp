#include "../include/Inventory.hpp"

Inventory::Inventory() {}

void Inventory::setTexture(sf::Texture* texture)
{
	m_texture = texture;
}

void Inventory::Draw(sf::RenderTexture* renderTexture_noShader)
{
	for (auto item : m_items)
	{
		item.Draw(renderTexture_noShader);
	}
}

void Inventory::addItem(std::string name, sf::IntRect quad)
{
	Item item(name, quad, m_texture, m_items.size());
	m_items.insert(m_items.end(), item);
}

void Inventory::removeItem(std::string name)
{
	for (unsigned int i = 0; i < m_items.size(); i++)
	{
    	if (m_items[i].getName() == name)
    	{
        	m_items.erase(m_items.begin() + i);
    	}
	}
}