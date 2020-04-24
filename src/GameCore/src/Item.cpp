#include "../include/Item.hpp"

Item::Item(std::string name, sf::IntRect quad, sf::Texture* texture)
{
	m_name = name;
	m_texture = texture;
	m_sprite.setTextureRect(quad);
	m_sprite.setTexture(*m_texture, false);
}

void Item::Draw(sf::RenderTexture* renderTexture)
{
	renderTexture->draw(m_sprite);
}

std::string Item::getName()
{
	return m_name;
}